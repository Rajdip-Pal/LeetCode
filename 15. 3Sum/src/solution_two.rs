#![allow(unused, dead_code)]

pub struct Solution {}

impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut numbers_set: std::collections::HashSet<i32> = std::collections::HashSet::from_iter(
            nums
        );
        println!("{:?}", numbers_set);
        vec![vec![]]
    }
}
