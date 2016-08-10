require './stats_object.rb'

PATH_TO_PROJECT = ARGV[0]
USER = ARGV[1]

stats = StatsObject.new

#####
## Count Number of commits for `User`
#####
path_to_project = PATH_TO_PROJECT
Dir.chdir path_to_project do 
    commits = `git shortlog -s -n`
    commits = commits.split("\n")
    commits = commits.select{ |item| item.include? USER }
    if commits.length > 0
        num_commits = commits.first.split(" ").first.to_i
        puts "Commits: #{num_commits}"
        stats.commits = num_commits
    end
end

#####
## Count Number of merge commits for `User`
#####
Dir.chdir path_to_project do 
    merges = `git log --pretty=format:"%h%x09%an%x09%ad%x09%s" | grep -i merge`
    num_merges = merges.split("\n").length
    puts "Merged: #{num_merges}"
    stats.merges = num_merges
end

#####
## Count Number of rebase commits for `User`
#####
Dir.chdir path_to_project do
    reflog = `git reflog`
    reflog_array = reflog.split("\n")
    num_rebases = reflog_array.select{ |command| command.include?("rebase") && command.include?("finish") }.length
    puts "Rebased: #{num_rebases}"
    stats.rebases = num_rebases
end

puts "Total stats for #{USER} on #{PATH_TO_PROJECT.split("/").last}: #{stats.calculate}"
