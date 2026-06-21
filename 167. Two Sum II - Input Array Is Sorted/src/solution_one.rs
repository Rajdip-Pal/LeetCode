#![allow(dead_code, unused)]

pub struct Solution {}

impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        let (mut pointer1, mut pointer2): (usize, usize) = (0, 0);

        while pointer1 < numbers.len() - 1 {
            pointer2 = pointer1 + 1;
            while pointer2 < numbers.len() {
                match (numbers[pointer1] + numbers[pointer2]).cmp(&target) {
                    std::cmp::Ordering::Equal => {
                        return vec![(pointer1 + 1) as i32, (pointer2 + 1) as i32];
                    }
                    std::cmp::Ordering::Greater => {
                        break;
                    }
                    _ => {}
                }
                pointer2 += 1;
            }
            pointer1 += 1;
        }

        vec![-1, -1]
    }
}
