#![allow(dead_code, unused)]

pub struct Solution {}

impl Solution {
    pub fn is_circular_sentence(sentence: String) -> bool {
        let mut chars = sentence.chars().collect::<Vec<char>>();
        if let (Some(x), Some(y)) = (chars.first(), chars.last()) {
            if x == y {
                for i in 1..chars.len() - 1 {
                    if chars[i] == ' ' && chars[i - 1] != chars[i + 1] {
                        return false;
                    }
                }
                true
            } else {
                false
            }
        } else {
            false
        }
    }
}
