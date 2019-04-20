#!/usr/bin/env ruby
require 'erb'
require 'benchmark'
require "#{File.dirname(__FILE__)}//function.rb"
require "#{File.dirname(__FILE__)}//utils.rb"
require "#{File.dirname(__FILE__)}//netlist2cnf.rb"
require "#{File.dirname(__FILE__)}//fujita88.rb"
require "#{File.dirname(__FILE__)}//malik88.rb"
require "#{File.dirname(__FILE__)}//force.rb"
require "#{File.dirname(__FILE__)}//parse_def.rb"
require "#{File.dirname(__FILE__)}//interleaving.rb"
require "#{File.dirname(__FILE__)}//mince.rb"
require "#{File.dirname(__FILE__)}//calc_span.rb"
require "#{File.dirname(__FILE__)}//test_bdd_lib.rb"
require "#{File.dirname(__FILE__)}//show_info_lib.rb"
require "#{File.dirname(__FILE__)}//constants_and_options.rb"
require "#{File.dirname(__FILE__)}//sendmail.rb"
require "#{File.dirname(__FILE__)}//parse_options.rb"


def processPreorder(_feature_model, _order_files)

  if _feature_model.children.size > 0
    group = Array.new()
    isLeaf = true
    _feature_model.children.each do |child|
      group << child.id.to_s
      processPreorder(child, _order_files)
      if child.children.size != 0
        isLeaf = false
      end
    end
    if group.size > 1 and isLeaf

      if (_feature_model.type = :or or _feature_model.type = :xor) and not _feature_model.parent.nil?
        group.unshift(_feature_model.parent.id.to_s)
      else
        group.unshift(_feature_model.id.to_s)
      end


      print "group:#{group.join(",")}\n"
      _order_files.keys.each do |key|
        position = Array.new()
        order_file = _order_files[key]
        group.each do |variable|
          index = order_file.order.find_index(variable)
          position << index.to_i
        end
        max = position.max
        min = position.min
        dif = max - min + 1
        msg = "#{key} size:#{group.size} max:#{max} min:#{min} dif:#{dif}"
        if group.size == dif
          msg = "****#{msg}"
        end
        print "#{msg}\n"
      end
    end
  end

end

class OrderFile
  attr_accessor :order, :found

  def initialize(_order, _found = 0)
    @order = _order
    @found = _found
  end
end

def processOrder(_filename)

  firstLine = true
  ret = Hash.new()

  File.open(_filename).readlines().each do |line|

    if not firstLine

      line = line.gsub("\n", "")
      values = line.split("\t")
      file = values[0]
      order = values[1]
      reorder = values[2]

      key = "#{file}-#{order}-#{reorder}"


      order_symbols = values[3]
      order_symbols = order_symbols.gsub("[", "")
      order_symbols = order_symbols.gsub("]", "")
      order_symbols = order_symbols.gsub(/\s+/, "")
      order_symbols = order_symbols.gsub(":", "")
      order_symbols = order_symbols.split(",")

      ret[key] = OrderFile.new(order_symbols)

    end
    firstLine = false
  end

  return ret

end


order_files = processOrder("order_file.txt")
#input_file = "../test/xml/REAL-FM-13.xml"

if ARGV.size > 0
  input_file = ARGV[0]
else
  exit(0)
end

circuit = FUNCTION.new(input_file, false)
test = processPreorder(circuit.extra_info.feature_model, order_files)


