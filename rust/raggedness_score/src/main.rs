/*
Raggedness Score
CPS 450 Activity 5
Prof: Dr. Patrick Kinnicutt
Author/Student: Marcus Shepherd <sheph2mj>
Language: Rust 1.12.0

Requires: https://www.rust-lang.org/en-US/
Optional: https://crates.io/

To run with rustc:
`cat input.txt | rustc raggedness_score/src/main.rs`

To run with cargo:
`cat input.txt | cargo run`

I personally recommend downloading cargo and running 
the script that way. Cargo can be installed on any OS.
Visit https://crates.io/install for download links.

Problem:
Compute the raggedness score for an arbitrary paragraph
of text. (Max 100 lines) Let `n` be the length in chars of 
the longest line of the paragraph. For each line less than n, 
that lines score will be (n - m)^2. The total raggedness 
will be the sum of each lines score.

My favorite thing about this assignment was learning some Rust.
Super interesting language.
*/
use std::io;
use std::io::prelude::*;


fn max_length(in_vec: &Vec<String>) -> i32{
    let mut max = 0;
    for item in in_vec{
        if item.len() > max {
            max = item.len();
        }
    }
    max as i32
}

fn collect_input() -> Vec<String> {
    let stdin = io::stdin();
    // Create new Vector of strings.
    let mut vect_in: Vec<String> = Vec::new();
    // For each line of input.
    for line in stdin.lock().lines() {
        let this_line = line.unwrap();
        // Push the line into the vector.
        vect_in.push(this_line.to_string());
        // unless it's a -1
        if this_line == "-1"{ break; }
    }
    vect_in
}

fn main(){
    // Input from console
    let mut vect_in = collect_input();
    // Max line length from Vector of input
    let max_line_length = max_length(&vect_in);
    // Final Score.
    let mut score: i32 = 0;
    let vector_size: i32 = vect_in.len() as i32;
    // remove last two items from vector
    vect_in.truncate((vector_size - 2) as usize);
    for item in vect_in{
        let mut line_score: i32;
        let line_len: i32 = item.len() as i32;
        // Any line less than the max length line
        if line_len < max_line_length{
            // line score = (n - m)
            line_score = max_line_length - line_len;
            // line score = line score ^ 2
            line_score = line_score.pow(2);
            if item.to_string() != "-1"{
                score += line_score;
            }
        }
    }
    // Print the final Raggedness Score.
    println!("{}", score);
}
