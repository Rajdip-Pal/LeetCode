#![allow(dead_code, unused)]

pub struct Solution {}

impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let (mut left, mut right): (usize, usize) = (0, height.len() - 1);
        let mut temp_index: usize = 0;
        let mut max_area: i32 = 0;

        while left < right {
            max_area = max_area.max(((right - left) as i32) * height[left].min(height[right]));

            if height[left] < height[right] {
                temp_index = left + 1;
                while temp_index < right && height[left] >= height[temp_index] {
                    temp_index += 1;
                }
                left = temp_index;
            } else {
                temp_index = right - 1;
                while left < temp_index && height[right] >= height[temp_index] {
                    temp_index -= 1;
                }
                right = temp_index;
            }
        }

        max_area
    }
}
