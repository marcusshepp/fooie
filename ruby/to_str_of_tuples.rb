file_name = "./lominger_competencies.txt"

puts "competency_categories = ("
File.open(file_name) do |f|
    f.each_line do |line|
        line = line.sub! "\n", ""
        puts "    \"#{line}\","
    end
end
puts ")"
