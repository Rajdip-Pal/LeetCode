#![allow(unused, dead_code)]

use std::hint;

pub struct Solution {}

impl Solution {
    pub fn min_eating_speed(piles: Vec<i32>, h: i32) -> i32 {
        let (mut left, mut right, mut mid): (usize, usize, usize) = (1, i32::MAX as usize, 0);
        let mut hours: i32 = 0;

        while left <= right {
            mid = left + (right - left) / 2;
            hours = {
                let mut value = 0;
                for i in &piles {
                    value += i / &(mid as i32);
                    if i % &(mid as i32) > 0 {
                        value += 1;
                    }
                }
                value
            };
            if hours > h {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left as i32;
    }
}
