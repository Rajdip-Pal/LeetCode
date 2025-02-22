#![allow(unused, dead_code)]

pub struct Solution {}

impl Solution {
    pub fn min_sub_array_len(target: i32, nums: Vec<i32>) -> i32 {
        let mut minimum_length: usize;
        let (mut left, mut right): (usize, usize) = (0, 0);
        let mut sum: i32 = nums.get(0).copied().unwrap();

        while right < nums.len() - 1 && sum < target {
            right += 1;
            sum += nums.get(right).unwrap();
        }

        if sum >= target {
            minimum_length = right - left + 1;

            for left in 1..nums.len() {
                sum -= nums.get(left - 1).unwrap();
                while right < nums.len() - 1 && sum < target {
                    right += 1;
                    sum += nums.get(right).unwrap();
                }
                if sum >= target {
                    minimum_length = minimum_length.min(right - left + 1);
                } else if right >= nums.len() - 1 {
                    break;
                }
            }
        } else {
            minimum_length = 0;
        }

        minimum_length as i32
    }
}
