mod solution_one;
use solution_one::Solution;

fn main() {
    println!("{}", Solution::rotate_string("abcde".to_string(), "deabc".to_string()));
    println!("{}", Solution::rotate_string("abce".to_string(), "deabc".to_string()));
    println!("{}", Solution::rotate_string("abcxe".to_string(), "deabc".to_string()));
    println!("{}", Solution::rotate_string("abce".to_string(), "eabc".to_string()));
    println!("{}", Solution::rotate_string("abcdefghijkl".to_string(), "dabcefijklgh".to_string()));
}
