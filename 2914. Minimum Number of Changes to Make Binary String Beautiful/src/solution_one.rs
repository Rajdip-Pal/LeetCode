#![allow(dead_code, unused)]

pub struct Solution {}

impl Solution {
    pub fn min_changes(s: String) -> i32 {
        let mut bit_to_change: i32 = 0;
        let binary_string: Vec<u8> = s.bytes().collect();
        for i in (0..binary_string.len()).step_by(2) {
            if binary_string.get(i).unwrap() != binary_string.get(i + 1).unwrap() {
                bit_to_change += 1;
            }
        }
        bit_to_change
    }
}
