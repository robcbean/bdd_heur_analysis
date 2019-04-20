require "#{File.dirname(__FILE__)}//netlist2cnf.rb"
require "#{File.dirname(__FILE__)}//splot_parser_ecr.rb"
require "#{File.dirname(__FILE__)}//id_generator.rb"
require "#{File.dirname(__FILE__)}//function_bench.rb"
require "#{File.dirname(__FILE__)}//function_splot.rb"
require "#{File.dirname(__FILE__)}//function_dimacs.rb"
require "#{File.dirname(__FILE__)}//constants_and_options.rb"


class Clause
  attr_accessor :id, :type, :name, :clause, :function, :inputs, :ex_clause, :null_function, :orig_inputs, :orig_clause, :old_inputs, :cross_tree

  def initialize(_id, _clause, _circuit)
    @id = _id
    @function = _circuit
    @inputs = Array.new()
    @clause = processClause(_clause)
    @ex_clause = @clause.clone()
    @null_function = false
    @name = ""
    @orig_clause = ""
    @old_inputs = Array.new()
    @cross_tree = false
  end

  def none()
    ret = ""
    return ret
  end


  def add_in_list(_variable)
    _variable = _variable.to_i
    if not @inputs.include?(_variable)
      @inputs.push(_variable)
    end
    return _variable
  end

  def NOT(_variable)
    _variable = @function.add_variable(_variable.to_i)
    add_in_list(_variable)
    ret = "!#{variable_name(@function.var_list, _variable)}"
    return ret
  end

  def AND(*_variables)
    ret = processOperator("&", _variables)
    return ret
  end

  def NAND(*_variables)
    ret = processOperator("&", _variables)
    ret = "!(#{ret})"
    return ret
  end

  def processOperator(_operator, _variables)
    ret = ""
    _variables.each do |variable|
      variable = @function.add_variable(variable)
      add_in_list(variable)
      if ret != ""
        ret = "#{ret} #{_operator} "
      end
      ret = "#{ret} #{variable_name(@function.var_list, variable)}"
    end
    return ret
  end

  def OR(*_variables)
    ret = processOperator("|", _variables)
    return ret
  end

  def DFF(_variable)
    _variable = _variable + 1000000
    _variable = @function.add_variable(_variable)
    _variable = @function.add_input(_variable)
    add_in_list(_variable)
    ret = "(#{variable_name(@function.var_list, _variable)})"


    return ret
  end

  def XOR(_p, _q)

    _p = @function.add_variable(_p)
    _q = @function.add_variable(_q)
    add_in_list(_p)
    add_in_list(_q)
    ret = "(#{variable_name(@function.var_list, _p)} & !#{variable_name(@function.var_list, _q)}) | (!#{variable_name(@function.var_list, _p)} & #{variable_name(@function.var_list, _q)})"
    return ret
  end

  def NOR(*_variables)
    ret = "!(#{processOperator("|", _variables)})"
    return ret
  end

  def BUFF(_variable)
    _variable = @function.add_variable(_variable)
    add_in_list(_variable)
    ret = "#{variable_name(@function.var_list, _variable)}"
    return ret
  end


  def processClause(_clause)
    ret = eval(_clause)
    return ret
  end


end

class FUNCTION

  attr_accessor :type, :name, :inputs, :var_list, :outputs, :clauses, :expanded_vars, :dfs_outputs, :dfs_inputs, :id_generator, :extra_info, :minisat

  def initialize(_name,_minisat=false, _var_list = Array.new(), _input = Array.new(), _output = Array.new(), _gates = Hash.new(), _var_names=Hash.new())
    @var_list = _var_list
    @inputs = _input
    @outputs = _output
    @clauses= _gates
    @type = nil
    @expanded_vars = Array.new()
    @conversion = Hash.new()
    @id_genertor = IdGenerator.new()
    @extra_info = nil
    @minisat = _minisat
    if File.exist?(_name)
      self.loadFromFile(_name)
    end
    #@name = _name

  end

  def getNullFunction()
    ret = @clauses.values.select { |clause| clause.null_function }
    if not ret.nil?
      ret = ret[0].id
    end
    return ret
  end

  def loadFromFile(_filename)
    if File.exist?(_filename)
      ext = File.extname(_filename).upcase
      self.name = File.basename(_filename)
      if ext == ".DIMACS"
        self.loadFromDIMACSFile(_filename)
        self.type = "DIMACS"
      elsif ext == ".XML"
        self.loadFromSPLOTFile(_filename)
        self.type = "SPLOT"
        self.name = get_feature_model_name(_filename)
      elsif ext == ".BENCH"
        self.loadFromBENCHFile(_filename)
        self.type = "BENCH"
      elsif ext ==".SPLX"
        self.loadFromSPLOTFile(_filename)
        self.type = "SPLOT"
      end
      self.calcDFSOutput()
    end
  end

  def calcDFSOutput()
    @dfs_outputs = self.getDFSOrderOutputs()
  end

  def calcDFSInput()
    @dfs_inputs = self.getDFSOrderInputs()
  end

  def add_variable(_variable)
    tmp_variable = _variable.to_i
    if not @var_list.include?(tmp_variable)
      @var_list.push(tmp_variable)
    end
    return tmp_variable
  end

  def add_input(_variable)
    tmp_variable = _variable.to_i
    if not @inputs.include?(tmp_variable)
      @inputs.push(tmp_variable)
    end
    return tmp_variable
  end

  def null_gates()
    ret = 0
    @clauses.each_value do |gate|
      if gate.null_function
        ret = ret + 1
      end
    end
    return ret
  end

  def add_output(_variable)
    tmp_variable = _variable.to_i
    if not @outputs.include?(tmp_variable)
      @outputs.push(tmp_variable)
    end
    return tmp_variable
  end

  def INPUT(_variable)
    add_variable(_variable)
    add_input(_variable)
  end

  def OUTPUT(_variable)
    add_variable(_variable)
    add_output(_variable)
  end


  def getOutputsByOrder()

    proc_vars = Array.new(@inputs)
    proc_output = Array.new(@clauses.keys)
    ret = Array.new()
    while proc_output.size() > 0
      proc_output.each do |gate_id|
        gate = @clauses[gate_id]
        all_included = true
        gate.inputs.each do |variable|
          if not proc_vars.include?(variable)
            all_included = false
            break
          end
        end
        if all_included
          ret.push(gate)
          print "gate #{gate.id}\n"
          if not proc_vars.include?(gate.id)
            proc_vars.push(gate.id)
          end
          proc_output.delete(gate.id)
          break
        end
      end
    end
    return ret
  end

  def allVariablesExpanded()
    ret = true
    self.clauses.values.each do |gate|
      if gate.old_inputs.nil?
        ret = false
        break
      else
        if (gate.old_inputs <=> gate.inputs) != 0
          ret = false
          break
        end
      end
      if not ret
        break
      end
    end
    return ret
  end


  def expand_clause(_clause)
    _clause.old_inputs = _clause.inputs.clone
    _clause.inputs.each do |input|
      if self.clauses.keys.include?(input)
        input_name = variable_name(self.var_list, input)
        self.clauses[input].inputs.each do |variable|
          if not _clause.inputs.include?(variable)
            _clause.add_in_list(variable)
            $stderr.print "Expanding clause #{_clause.id} variable #{variable}..\n"
          end
        end
        _clause.inputs.delete(input)
        #_gate.ex_clause.gsub!(input_name,"("+_circuit.gates[input].ex_clause+")")
        #_gate.ex_clause.gsub!(/\s+/, "")
      end
    end
  end


  def expandFunction()
    while not self.allVariablesExpanded()
      self.clauses.values.select{|gate| (gate.old_inputs <=> gate.inputs) != 0}.each do |clause|
      #self.clauses.values.each do |clause|
        expand_clause(clause)
      end
    end
  end


  def generateClausesArray(_gate_id,_calc_desc, _processed=Array.new(), _normal_clause=Array.new(), _extra_clause=Array.new(), _order)

    if not _processed.include?(_gate_id)
      $stderr.print "generating output gate: #{_gate_id}\n"
      _processed.push(_gate_id)
      gate = @clauses[_gate_id]
      inputs = gate.orig_inputs
      inputs.each do |input|
        if @clauses.keys.include?(input)
          generateClausesArray(input,_calc_desc, _processed, _normal_clause, _extra_clause, _order)
        end
      end
      if gate.orig_clause != ""
        _normal_clause << gate2CUDD(gate,_calc_desc)
      else
        _extra_clause << gate2CUDD(gate,_calc_desc)
      end
    end


  end

  def generateSingleClause(_gate_id, _calc_desc,_enable_autodyn, _processed)

    ret = ""
    if not _processed.include?(_gate_id)
      $stderr.print "generating output gate: #{_gate_id}\n"
      _processed.push(_gate_id)
      gate = @clauses[_gate_id]
      #inputs  = gate.orig_inputs
      gate.orig_inputs.each do |input|
        if @clauses.keys.include?(input)
          tmpgate = generateSingleClause(input,_calc_desc,_enable_autodyn, _processed)
          if tmpgate.gsub(/\s+/, "") != ""
            if ret != ""
              ret = "#{ret}\n"
            end
            ret = "#{ret}\t#{tmpgate}"
          end
        end
      end


      if @outputs.include?(_gate_id)
        #ret = ret + "\n\t//kk #{_gate_id}\n"
        if gate.null_function
          ret = ret + "\n\t//Null Function"
          ret = ret + "\n\t#{variable_name(@var_list, _gate_id)} = mgr.bddOne();\n"
          if _calc_desc
            ret = ret + "\n\tdesc_t1 = get_user_time();\n"
          end
          i = 0
          if _calc_desc and _enable_autodyn
            ret = ret + "\n\tmgr.AutodynDisable();"
          end
          @outputs.each do |output_id|
            #ROB : 03/06/2018 Generate total gate on this disable autodyn and after enable y calc_desc
            output_gate = @clauses[output_id]
            if not output_gate.null_function
              ret = ret + "\n\t#{variable_name(@var_list, _gate_id)} = #{variable_name(@var_list, _gate_id)} & output[#{i}];\n"
              if _calc_desc
                ret = ret + "\n\tpoutput[#{i}] = output[#{i}].getNode();\n"
              end
              i = i + 1
            end
          end
        end
      else
        ret = ret + "#{gate2CUDD(gate,_calc_desc)}"
        #ROB : 02/04/2018 Find value in other gate
        if ( gate.orig_inputs & @inputs ).size == 0 and not gate.null_function
          gate.orig_inputs.each do |input|
            ret = ret + "\n\tCudd_RecursiveDeref(mgr.getManager(),#{variable_name(@var_list, input)}.getNode());"
          end
        end

        #ROB : 02/04/2018 Check if gate is included in ouputs
        i = 0
        @outputs.each do |output_id|
          output_gate  = @clauses[output_id]
          if not output_gate.null_function
            if output_gate.orig_inputs.include?(_gate_id)
              ret = ret + "\n\tstd::cerr<<\"Appending gate to output[#{i}] #{variable_name(@var_list, _gate_id)}\"<<std::endl;"
              ret = ret + "\n\toutput[#{i}]=output[#{i}] & #{variable_name(@var_list, _gate_id)};"
              break
            end
            i = i + 1
          end
        end

      end
    end

    return ret

  end

  def gate2CUDD(_gate,_calc_des)

    ret = "\n\tstd::cerr<<\"processing gate #{_gate.id}...\"<<std::endl;\n"

    if _gate.null_function and _calc_des
      i = 0
      _gate.orig_inputs.uniq.each do |input|
        ret = "#{ret}\tpoutput[#{i}] = x[#{input}].getNode();\n"
        ret = "#{ret}\tsum_nodes = sum_nodes + Cudd_DagSize(x[#{self.var_list.find_index(input)}].getNode());\n"
        i = i + 1
      end
    end

    ret = "#{ret}\t#{variable_name(@var_list, _gate.id)} = #{_gate.clause};//#{_gate.orig_clause.gsub(/\s+/, " ")}"

    ret = "#{ret}\n\tcount_nodes_vector.push_back(#{variable_name(@var_list, _gate.id)});"
    ret = "#{ret}\n\tcount_nodes.push_back(mgr.SharingSize(count_nodes_vector));"
    ret = "#{ret}\n\tcount_id.push_back(#{_gate.id});"

    return ret
  end

  def generateClauses(_calc_desc,_enable_autodyn,_order)

    ret = ""
    gate_count = 0
    processed = Array.new()
    normal_clause = Array.new()
    extra_clause = Array.new()
    @clauses.keys.each do |output|
      if @clauses[output].null_function
        ret = generateSingleClause(output,_calc_desc,_enable_autodyn, processed)
      end
    end

    return ret

  end


  def getDFSOrderInputs(_orig_inputs=false, _output=find_last_output(self),_processed=Array.new())
    ret = Array.new()
    if not _processed.include?(_output)
      _processed << _output
      if _orig_inputs
        inputs = @clauses[_output].orig_inputs
      else
        inputs = @clauses[_output].inputs
      end
      inputs.each do |gate|
        if not isConnectedToPrimaryInput(self, gate)
          ret = ret.concat(getDFSOrderInputs(_orig_inputs, gate,_processed))
          ret.uniq!
        else
          ret.push(gate)
        end
      end
    end
    return ret
  end


  def generatePrevOutPuts(_order)
    i = 0
    ret = ""
    self.outputs.each do |output|
      if not self.clauses[output].null_function
        if ret != ""
          ret = ret + "\n"
        end
        ret = ret + "\toutput[#{i}]=mgr.bddOne();"
        i = i + 1
      end
    end
    return ret
  end


  def generateOutputs(_order)
    i = 0
    ret = ""
    self.outputs.each do |output|
      if not self.clauses[output].null_function
        if ret != ""
          ret = ret + "\n"
        end
        ret = ret + "\toutput[#{i}]=x[#{self.var_list.find_index(output)}];\n"
        i = i + 1
      end
    end
    return ret
  end

  def getDFSOrderOutputs(_output=find_last_output(self),_processed = Array.new())
    ret = Array.new()
    if not _processed.include?(_output)
      _processed << _output
      if @clauses.keys.include?(_output)
        $stderr.print "Processing dfsorderoutput clause #{_output}..\n"
        ret.push(_output)
        @clauses[_output].orig_inputs.each do |gate|
          #print "gate:#{gate} #{@gates.values.include?(gate)}\n"
          ret = ret.concat(getDFSOrderOutputs(gate,_processed))
          ret.uniq!
        end
      end
    end
    return ret
  end

  def getNotUsedInputs()

    ret = Array.new()
    dfs_order = self.getDFSOrderInputs(self.outputs[self.outputs.size-1])
    @inputs.each do |input|
      if not dfs_order.include?(input)
        ret << input
      end
    end
    return ret

  end


end
