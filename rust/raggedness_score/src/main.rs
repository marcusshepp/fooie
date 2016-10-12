/*
Raggedness Score
CPS 450 Activity 5
Prof: Dr. Patrick Kinnicutt
Author/Student: Marcus Shepherd <sheph2mj>
Language: Rust 1.12.0

Problem:
Compute the raggedness score for an arbitrary paragraph of text. (Max 100 lines)
Let `n` be the length in chars of the longest line of the paragraph.
For each line less than n, that lines score will be (n - m)^2 
The total raggedness will be the sum of each lines score.
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

fn main(){
    // intro(); 
    let stdin = io::stdin();
    let mut in_arr: Vec<String> = Vec::new();
    for line in stdin.lock().lines() {
        let foo = line.unwrap();
        in_arr.push(foo.to_string());
        if foo == "-1"{ break; }
    }
    let max_line_length = max_length(&in_arr);
    let mut score: i32 = 0;
    let vector_size: i32 = in_arr.len() as i32;
    in_arr.truncate((vector_size - 2) as usize);
    for item in in_arr{
        let mut line_score: i32;
        let line_len: i32 = item.len() as i32;
        if line_len < max_line_length{
            line_score = max_line_length - line_len;
            line_score = line_score.pow(2);
            if item.to_string() != "-1"{
                score += line_score;
            }
        }
    }
    println!("Final Score: {}", score);
}
