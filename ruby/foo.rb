
=begin
Ruby script for toying with Ruby
=end

# arr = ["a", "b", "c", "d", "e"]
# 
# puts arr.max
# puts arr.min
# 
# def max (a,b)
#   a>b ? a : b
# end
# 
# puts arr.min_by { |x| x.length }
# puts arr.max_by { |x| x.length }

## regex
# foo = "marcus shepherd is here"
# substring = "marcus"
# puts foo.match(/[^|\s]#{substring}[\s|$]/)

## testing if/unless
# x = ""
# puts "foo" if x
# same as
# puts "foo" unless x.nil?

## Ternary Operator
# x = 1 ? 2 : 3
# puts x # >> 2

# puts (x.nil? ? "pop" : "bar") # >> "bar"

## string split/join
# string = "marcus is my name"
# splitted = string.split " "
# joined = splitted.join " "
# puts joined

## string include?
# bad_words = ["foo", "bar", "marcus"]
# if bad_words.any? { | w | string.include? w }
  # puts "yes"
# else
  # puts "no"
# end

## function returns
# def foo
  # return "foo"
  # x = "dont print this"
# end

# puts foo
# puts 1/0

# class Foo
# 	def self.add(*args)
# 		r = 0
# 		if args.length > 1
# 			args.each { |a| r += a.to_i }
# 		else
#			r += (args[0].to_i + args[0].to_i)
#		end
#		return r
#	end
#end

#f = Foo
#puts f.add(1, 2)

# a = [1, 2, 3, 4, 5]
# b = [45, 123, 5768]
# c = ["Fpp", "bar", "foo"]

# d = a << b << c
# puts d.flatten

# class A
#   b = "pop"
#   def foo
#     a = "lol"
#     puts local_variables
#   end
# end
# 
# a = A.new
# a.foo

x = [[1, 2], [1, 3], [2, 4]]
puts x.any?{|i| i.include?(2) }