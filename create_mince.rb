#!/usr/bin/env ruby

require "#{File.dirname(__FILE__)}//function.rb"
require "#{File.dirname(__FILE__)}//constants_and_options.rb"
require "#{File.dirname(__FILE__)}//mince.rb"


def generateMinceFile(_filename)

  circuit = FUNCTION.new(_filename,false)
  mince_order = mince(circuit,true)

end


if ARGV.size > 0
  (1..10).each do |i|
    if Dir.exist?(ARGV[0])
      path = ARGV[0]
      Dir.glob(File.join(path,"*.*")).each do |file|
        generateMinceFile(file)
      end
    else
      file = ARGV[0]
      generateMinceFile(file)
    end
  end
end
