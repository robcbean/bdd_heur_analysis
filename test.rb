#!/usr/bin/env ruby


Dir.glob("/Users/rbean/Uned/bdd_heur_analysis/thesis/models/xml_reduction/*.xml").each do |filename|
    if File.file?(filename)
        print "Processing #{filename}\n"
        data = File.open(filename).read
        data.gsub!(/feature_model\s+name=\"\w+\"/,"feature_model name=\"#{File.basename(filename)}\"")
        fd = File.open(filename,"w")
        fd.write(data)
        fd.close
    end
end
