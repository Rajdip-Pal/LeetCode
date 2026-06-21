mod solution_one;
use solution_one::Solution;

fn main() {
    println!("{}", Solution::min_sub_array_len(11, vec![1, 2, 3, 4, 5]));
}
