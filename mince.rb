require "#{File.dirname(__FILE__)}//constants_and_options.rb"
require 'fileutils'

def generateDIMACS(_circuit)


  clauses =  Array.new()
  _circuit.clauses.each do |clause_pair|
    key = clause_pair[0]
    clause = clause_pair[1]
    if (clause.inputs & _circuit.clauses.keys).size == 0
      #Get regular expressions
      clause.clause.split("&").each do |strvalue|
        outvars = Array.new()
        strvalue = strvalue.gsub("(","")
        strvalue = strvalue.gsub(")","")
        strvalue.split("|").each do |value|
          value = value.gsub("x","")
          value = value.gsub("[","")
          value = value.gsub("]","")
          if value.include?("!")
            negate = true
          else
            negate = false
          end
          value = value.gsub("!","")
          int_value = value.to_i + 1
          if negate
            int_value = -int_value
          end
          outvars << (int_value).to_s
        end
        clauses << "#{outvars.join(" ")} 0"
      end
    end
  end
  dimacs =  "p cnf #{_circuit.inputs.size} #{clauses.size}\n"
  dimacs = dimacs + clauses.join("\n")
  fd = File.open(getCNFMINCEFile(),"w")
  fd.write(dimacs)
  fd.close()

end


def writeOrder(_filename,_order,_append)
  if _append
    write_options = 'a'
  else
    write_options = 'w'
  end
  fd = File.open(_filename, write_options)
  str_output = _order.join(',')
  str_output =  "#{str_output}\n"
  fd.write(str_output)
  fd.close
end

def readOrder(_filename)
  fs = File.open(_filename,'r')
  lines = fs.readlines()
  ret = lines[rand(lines.size)]
  ret = ret.gsub("\n","")

  ret = ret.split(',')
  ret = ret.map{|x| x.to_i }
  return ret
end


def cnf2hgraph()

  #delete previus generated files
  Dir.glob("out.*").each do |file|
    File.delete(file)
  end
  cmd = "mince/cnf2hgraph.pl #{getCNFMINCEFile()}"
  `#{cmd}`

end

def metaPlacerTest()
  cmd = "mince/MetaPlacerTest0.exeS -f out.aux -saveXorder"
  `#{cmd}`
end

def  cnfRename()
  cmd = "mince/cnf_rename_vars.pl left2right.ord #{getCNFMINCEFile()} #new_{getCNFMINCEFile()}"
  `#{cmd}`
end

def leftOrderFileCircuit(_circuit)

  circuit_name = _circuit.name
  if circuit_name.include?('/')
    circuit_name = File.basename(circuit_name)
  end

  ret = "mince/generated_orders/#{circuit_name}.ord"


  return ret
end

def getMINCEOrder(_circuit,_append)

  ret  = Array.new()
  File.open(getLeftOrderFile()).each do |line|
    line = line.gsub("v","")
    line = line.gsub("\n","")
    ret << (line.to_i-1)
  end

  writeOrder(leftOrderFileCircuit(_circuit), ret, _append)

  return ret

end

def mince(_circuit,_append = false)

  if not File.exist?(leftOrderFileCircuit(_circuit)) or _append
    generateDIMACS(_circuit)
    cnf2hgraph()
    metaPlacerTest()
    ret = getMINCEOrder(_circuit,_append)
  else
    ret = readOrder(leftOrderFileCircuit(_circuit))
  end

  ret = ret  & _circuit.getDFSOrderInputs(_circuit.outputs[_circuit.outputs.size-1])

  return ret

end