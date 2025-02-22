#![allow(dead_code, unused)]

pub struct Solution {}

impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        let mut find_value: i32 = 0;
        let (mut left, mut right, mut mid): (usize, usize, usize) = (0, numbers.len() - 1, 0);
        for i in 0..numbers.len() - 1 {
            find_value = target - numbers[i];
            left = i + 1;
            right = numbers.len() - 1;
            while left <= right {
                mid = left + (right - left) / 2;
                if numbers[mid] == find_value {
                    return vec![(i + 1) as i32, (mid + 1) as i32];
                } else if numbers[mid] > find_value {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        vec![-1, -1]
    }
}
