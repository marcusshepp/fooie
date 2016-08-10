module A
    def foo
        "hello"
    end
    module_function :foo
    class B
        def self.bar
            foo
        end
    end
end

b = A::B.new

puts b

    
