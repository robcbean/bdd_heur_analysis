#!/usr/bin/env ruby
require 'erb'
require 'benchmark'
require "#{File.dirname(__FILE__)}//function.rb"
require "#{File.dirname(__FILE__)}//utils.rb"
require "#{File.dirname(__FILE__)}//force.rb"

if ARGV.size > 0
  if File.file?(ARGV[0])
    function = FUNCTION.new(ARGV[0])
    hypergrah = generateHyperGraph(function)

    fdh = File.open(function.name + "_h.dot","w")
    fdc = File.open(function.name + "_c.dot","w")

    fdh.write("graph \"#{function.name}\" { \n" )
    fdc.write("graph \"#{function.name}\" { \n" )

    hypergrah.hyperedges.each do |edge|

      hypergrah.variables.combination(2).to_a.each do |pair|
        if not function.clauses[edge.name].cross_tree
          fdh.write("\t #{pair[0]} -- #{pair[1]};\n")
        else
          fdc.write("\t #{pair[0]} -- #{pair[1]};\n")
        end
      end

    end

    fdh.write("\n}")
    fdh.close()

    fdc.write("\n}")
    fdc.close()



  end
end
