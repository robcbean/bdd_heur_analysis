#!/usr/bin/env ruby
require 'erb'
require 'os'
require 'benchmark'
require "#{File.dirname(__FILE__)}//function.rb"
require "#{File.dirname(__FILE__)}//utils.rb"
require "#{File.dirname(__FILE__)}//netlist2cnf.rb"
require "#{File.dirname(__FILE__)}//fujita88.rb"
require "#{File.dirname(__FILE__)}//malik88.rb"
require "#{File.dirname(__FILE__)}//force.rb"
require "#{File.dirname(__FILE__)}//parse_def.rb"
require "#{File.dirname(__FILE__)}//interleaving.rb"
require "#{File.dirname(__FILE__)}//calc_span.rb"
require "#{File.dirname(__FILE__)}//narodytska.rb"
require "#{File.dirname(__FILE__)}//mendonca.rb"
require "#{File.dirname(__FILE__)}//preorder_random.rb"
require "#{File.dirname(__FILE__)}//symmetry.rb"
require "#{File.dirname(__FILE__)}//constants_and_options.rb"




def getVarNum(_var_list,_variable)
  ret = -1
  ret = _var_list.find_index(_variable)
  return ret
end


def selectBestOrderBySpan(_span)
  ret = ""
  best_span = Float::INFINITY

  _span.each do |heur, span|
    if span < best_span
      best_span = span
      ret = heur
    end
  end

  return ret

end


def getHeader(_minisat, _calc_desc, _options)
  ret = "file\torder\treorder\talgo_time\tbdd_time\treorder_time"
  if _calc_desc
    ret = ret + "\tand_time\treach_one\treach_one_total\treach_one_decomposed\tdead\tcore\tsum_nodes"
  end

  ret = ret + "\tminterms"
  ret = ret + "\tspan"
  ret = ret + "\tecr"

  if calcComplexity? or calcAllSpan? or calcNewSpan?
    if calcComplexity?
      ret = ret + "\tcomplexity"
    else
      if calcAllSpan?
        ret = ret + "\tall_span"
      else
        ret = ret + "\tnew_span"
      end
    end
  end

  ret = ret + "\t#{headerInfo}"


  if _options[:count_symmetric]
    ret = ret + "\ttotal_possible_symmetric"
    ret = ret + "\tsymmetric_percent"
    ret = ret + "\tbefore_symmetric_continuos"
    ret = ret + "\tafter_symmetric_continuos"
  end

  ret = ret + "\tmaxnode\ttotal"

  ret = ret + "\n"

  return ret
end

def get_reorder_heurists(_heuristics)
  ret = Array.new()
  _heuristics.each do |heuristic|
    if not ret.include?(heuristic.reorder)
      ret << heuristic.reorder
    end
  end
  if ret.size == 0
    ret << "none"
  end
  return ret
end

# TODO : ROB 13/04/16 add a random heuristic, it's necessary
def generate_random_heuristics(_function, _cpu_time, _heuristics, _number_of_orders, _number_of_variables)

  (0.._number_of_orders - 1).to_a.each do |random_order|

    preorder = _function.getDFSOrderInputs(true)

    tmp_order = Permutation.new(preorder.size).random.value
    order = Array.new()
    tmp_order.each do |variable|
      order << preorder[variable]
    end


    get_reorder_heurists(_heuristics).each do |reorder|

      heuristic = Heur.new("random#{random_order}", order)
      heuristic.reorder = reorder
      heuristic.print_name = "random_#{random_order}"
      _heuristics << heuristic
      _cpu_time[heuristic.name] = 0.0

    end

  end

end


def process_file(_input_file, _output_file, _heuristics_file, _wait_time, _random_orders, _grown_file, _minisat, _best_span, _calc_desc, _write_dot, _mcl, _count_symmetric, _enable_autodyn, _avg_length_path, _output_order)


  function = FUNCTION.new(_input_file, _minisat)
  heuristics = Array.new()


  basename = File.basename(_output_file)
  extname = File.extname(_output_file)
  basename.gsub!(/#{extname}/, "")
  cc_file = _output_file
  cpu_time = Hash.new()

  parse_definition_orders = get_parse_definitions_orders(_heuristics_file)
  calc_desc = _calc_desc
  write_dot = _write_dot
  enable_autodyn = _enable_autodyn
  count_symmetric = _count_symmetric

  cpu_time["netlist"] = 0.0
  if parse_definition_orders.include?(fujita())
    $stderr.print "generating #{_input_file} fujita order ...\n"
    cpu_time[fujita()] = Benchmark.measure {$order_fujita = fujita88(function)}.utime
    order_fujita = $order_fujita
  end
  if parse_definition_orders.include?(malik_fanin())
    $stderr.print "generating #{_input_file} malik fanin order ...\n"
    cpu_time[malik_fanin()] = Benchmark.measure {$order_malik_fanin = malik88fanin(function)}.utime
    order_malik_fanin = $order_malik_fanin
  end
  if parse_definition_orders.include?(malik_level())
    $stderr.print "generating #{_input_file} malik level order ...\n"
    cpu_time[malik_level()] = Benchmark.measure {$order_malik_level = malik88level(function)}.utime
    order_malik_level = $order_malik_level
  end
  if parse_definition_orders.include?(fujii())
    $stderr.print "generating #{_input_file} fuji93 level order ...\n"
    cpu_time[fujii()] = Benchmark.measure {$order_fuji_inter = getFuji1993(function)}.utime
    order_fuji_inter = $order_fuji_inter
  end

  #ROB : 05/05/2017 MICE
  if parse_definition_orders.include?(MINCE())
    $stderr.print "generating #{_input_file} mince level order ...\n"
    cpu_time[MINCE()] = Benchmark.measure {$order_mince = mince(function)}.utime
    order_mince = $order_mince
  end

  #ROB : 14/08/17 Preorder random
  if parse_definition_orders.include?(preorderRandom())
    $stderr.print "generation #{_input_file} preorderrandom level order ...\n"
    cpu_time[preorderRandom()] = Benchmark.measure {$preorder_random = generatePreorderRandom(function, _random_factor)}.utime
    preorder_random = $preorder_random
  end


  if function.type == "SPLOT"
    if parse_definition_orders.include?(narodyska())

      $stderr.print "generating #{_input_file} narodyska order ...\n"
      cpu_time[narodyska()] = Benchmark.measure {$order_narodyska = getNarodystka(function)}.utime
      $stderr.print "generating #{_input_file} narodyska order ...\n"
      order_narodyska = $order_narodyska
      if _mcl != ""
        values = _mcl.split("-")
        range = Range.new(values[0].to_f, values[2].to_f)
        range.step(values[1].to_f) do |i|
          naro_name = "narodyska-#{i}"
          cpu_time[naro_name] = Benchmark.measure {$order_narodyska = getNarodystka(function, i)}.utime
          heuristic = Heur.new(naro_name, $order_narodyska)
          heuristic.print_name = naro_name
          heuristics << heuristic
        end
      end
    end

    if parse_definition_orders.include?(mendonca())
      res_mendoca = getMendonca(_input_file, function, _wait_time)
      if not res_mendoca.nil?
        cpu_time[mendonca()] = res_mendoca.heuristic_time
        $order_mendonca = res_mendoca.order
        order_mendonca = $order_mendonca
      else
        $order_mendonca = nil
      end
    end

  end


  $stderr.print("expanding function  #{function.name}...\n")
  function.expandFunction()
  if parse_definition_orders.include?(FORCE())
    $stderr.print "generating #{_input_file} force order...\n"
    cpu_time["force"] = Benchmark.measure {$order_force = getFORCEOrder(function)}.utime
    order_force = $order_force
  end

  #<< ROB : 20/11/2016 add symmetry order
  if parse_definition_orders.include?("symmetry")
    $stderr.print "generating symmetry order ...\n"
    cpu_time["symmetry"] = Benchmark.measure {$order_symmetry = order_symmetry(function)}.utime
    order_symmetry = $order_symmetry
  end
  #<< ROB : 20/11/2016 add symmetry order

  cpu_time.keys.each do |key|
    value = cpu_time[key]
    cpu_time[key] = "%0.10f" % value
  end


  circuit = function

  heuristics.concat(parse_definition(function, binding, _heuristics_file))

  generate_random_heuristics(circuit, cpu_time, heuristics, _random_orders, function.inputs.size)
  span = calcSpanAndComplexity(function, heuristics)

  function.calcDFSInput()
  grown_file = _grown_file

  #<< ROB : 20/12/2016 If select best span only select the best heuristic
  if _best_span
    best_order = selectBestOrderBySpan(span)
    heuristics.select! {|heur| heur.name == best_order}
  end
  #<< ROB : 20/12/2016 If select best span only select the best heuristic

  heuristics.each do |heur|

    if not heur.order.nil?

      if printOrder and not circuit.extra_info.nil?
        order_names = Array.new()
        heur.order.each do |variable|
          order_names << circuit.extra_info.variables[variable]
        end
        $stderr.print("HeuristicOrder #{heur.name}: #{order_names.to_s}\n")
      end

      if heur.reorder == ""
        reorder = "NONE"
      else
        reorder = heur.reorder
      end

          #<< ROB : 15/12/2016 if group and reorder group order
      if circuit.type == "SPLOT" and heur.group and ["CUDD_REORDER_SYMM_SIFT", "CUDD_REORDER_GROUP_SIFT"].include?(heur.reorder) and printOrder
        heur.order = generatePermutationAccordingGroups(circuit.inputs, heur.order, circuit.extra_info.symmetric_groups)
        if printOrder
          order_names = Array.new()
          heur.order.each do |variable|
            order_names << circuit.extra_info.variables[variable]
          end
          $stderr.print("HeuristicOrder interleving #{heur.name} #{order_names.to_s}\n")
        end
      end
      #<< ROB : 15/12/2016 if group and reorder group order
      msgOrderFile = "#{circuit.name}\t#{heur.name}\t#{heur.reorder}\t#{order_names.to_s}\n"
      fd = File.open(orderFile(), 'a')
      fd << msgOrderFile
      fd.close()
      # << ROB : 17/01/2018 We have the real order

      $stderr.print "generating c++ file #{cc_file} ...\n"
      erbFile = File.join(File.dirname(__FILE__), "test_bdd_heuristic.erb")
      $stderr.print "erbfile: #{erbFile}\n"
      render = ERB.new(File.new(erbFile).read())
      output = render.result(binding)

      fd = open(File.join(File.dirname(__FILE__), cc_file), "w")
      fd.write(output)
      fd.close()


      $stderr.print "compiling #{cc_file} ...\n"
      base_dir = "../../bdd/src/cudd-3.0.0/"
      if OS.linux?
        base_dir = "../../bdd/src/cudd-3.0.0_mod_linux/"
        lib = "linuxcudd"
        path = "./libcuddlinux/"
      elsif OS.mac?
        base_dir = "../../bdd/src/cudd-3.0.0_mod_imac/"
        lib = "maccudd"
        path = "./libcuddmac/"
      end
      include_dir = " -I #{base_dir}cplusplus/ -I #{base_dir}mtr/ -I #{base_dir}cudd/ -I #{base_dir}epd/  -I #{base_dir}st/ -I #{base_dir}util/ -I #{base_dir}"
      if not OS.mac?
        include_dir = "-static #{include_dir}"
      end
      compiler = "g++ "
      compiler = compiler + " -std=gnu++11 -fpermissive "


      cmd = "#{compiler} #{include_dir}   output.cc operations.cc -L #{path} #{getOptimization} #{getDebug} #{cc_file}  -l #{lib}  -o #{basename}"

      `#{cmd}`
      $stderr.print "executing #{basename} ...\n"
      output = `./#{basename}`
      print "#{output}"
    else
      #<< ROB : 08/01/2017 Replace include path
      include_dir.gsub!("../../bdd/src/cudd-3.0.0/", "/cygdrive/c/Users/Roberto/Dropbox/Uned/Doctorado/bdd/src/cudd-3.0.0/")
      #>> ROB : 08/01/2017 Replace include path
      cmd = "c:\\cygwin64\\bin\\bash.exe --login -c \"g++  #{include_dir}   #{srcPathCygWin}/#{cc_file}   #{srcPathCygWin}/output.cc #{srcPathCygWin}/operations.cc  -std=gnu++11 -L /usr/local/lib  -lcudd -o  #{srcPathCygWin}/#{basename}\" "
      $stderr.print "comando:#{cmd}\n"
      `#{cmd}`
      $stderr.print "executing #{basename} ...\n"
      cmd = "c:\\cygwin64\\bin\\bash.exe --login -c \"  #{srcPathCygWin}/#{basename}.exe \""
      output = `#{cmd}`
      print "#{output}"
    end
    $stdout.flush
    $stderr.flush

  end

end















