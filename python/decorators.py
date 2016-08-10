def p_decorate(func):
   def func_wrapper(name):
       bar = "bar"
       return bar
   return func_wrapper
   

@p_decorate
def foo(name):
    print bar
    return name
    
print foo("marcus")