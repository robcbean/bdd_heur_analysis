#!/usr/bin/env ruby
require "#{File.dirname(__FILE__)}//function.rb"
require "#{File.dirname(__FILE__)}//constants_and_options.rb"


def getTableConversion()
  convert_filename = "../../complementary_information/conversion_modelos_ficheros_a_nombres/conversion_simple.txt"
  convert_fd  =  File.open(convert_filename,"r")
  table_conv = Hash.new()

  convert_fd.readlines.each do |line|
    line = line.gsub("\n","")
    values = line.split("\t")
    filename = values[0]
    name = values[1]
    table_conv[filename] = name
  end
  ret = table_conv
  return ret
end



def printValues(_filename,_convert_filename)
  model = FUNCTION.new(_filename, true)
  psg_vars = 0
  model.extra_info.symmetric_groups.each do |group|
    psg_vars = psg_vars + group.variables.size
  end

  total_variables = model.getDFSOrderInputs.size
  psg_prc = psg_vars.to_f / total_variables.to_f * 100
  psg_prc = psg_prc.round(5)
  model_name = model.name.gsub("../thesis/xml","")
  if _convert_filename.keys.include?(model_name)
    model_name = _convert_filename[model_name]
  end
  print "#{model_name}\t#{total_variables}\t#{psg_vars}\t#{psg_prc}\n"

end



if ARGV.size > 0
  table_conv = getTableConversion()
  print "file\tinputs\tpsg\tprc\n"
  if Dir.exist?(ARGV[0])
    path = ARGV[0]
    Dir.glob(File.join(path,"*.*")).each do |file|
      printValues(file,table_conv)
    end
  else
    filename = ARGV[0]
    printValues(filename,table_conv)
  end
end