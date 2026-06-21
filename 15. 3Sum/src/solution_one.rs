#![allow(dead_code, unused)]

pub struct Solution {}

impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        nums.sort();

        let mut target = 0;
        let (mut left, mut right, mut mid): (usize, usize, usize) = (0, nums.len() - 1, 0);
        let mut result: std::collections::HashSet<Vec<i32>> = std::collections::HashSet::new();

        for i in 0..nums.len() - 2 {
            for j in i + 1..nums.len() - 1 {
                target = 0 - nums[i] - nums[j];
                left = j + 1;
                right = nums.len() - 1;

                while left <= right {
                    mid = left + (right - left) / 2;
                    if nums[mid] == target {
                        result.insert(vec![nums[i], nums[j], nums[mid]]);
                        break;
                    } else if nums[mid] < target {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
        }

        let mut final_result: Vec<Vec<i32>> = Vec::new();
        for item in result {
            final_result.push(item);
        }
        final_result
    }
}
