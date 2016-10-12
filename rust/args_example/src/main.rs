use std::env;


fn main(){
    let args: Vec<String> = env::args().collect();

    // The first argument is the path that was used to call the program.
    println!("My path is {}", args[0]);

    // The rest of the args are the passed command line parameters.
    // call the program like this:
    // $ ./script arg1 arg2
    println!("I got {:?} arguments: {:?}", args.len() - 1, &args[1..]);
}
