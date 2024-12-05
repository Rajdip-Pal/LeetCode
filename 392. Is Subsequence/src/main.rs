mod solution_one;
use solution_one::Solution;

fn main() {
    println!("{}", Solution::is_subsequence("ac".to_string(), "ahbgdc".to_string()));
}
