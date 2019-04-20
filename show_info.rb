#!/usr/bin/env ruby
require 'descriptive-statistics'
require "#{File.dirname(__FILE__)}//function.rb"
require "#{File.dirname(__FILE__)}//utils.rb"
require "#{File.dirname(__FILE__)}//show_info_lib.rb"


if ARGV.size > 0
  print "file\t#{headerInfo}\tecr\n"
  if File.file?(ARGV[0])
    info = getFunctionInfo(ARGV[0])
    print "#{ARGV[0]}\t#{info.to_s}\t#{info.function.extra_info.ecr}\n"
  else
    Dir.glob(File.join(ARGV[0], "/*.*")).each do |file|
      if File.file?(file)
        info = getFunctionInfo(file)
        $stdout.print "#{file}\t#{info.to_s}\t#{info.function.extra_info.ecr}\n"
      end
    end
  end
end




