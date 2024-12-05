#![allow(dead_code, unused)]

pub struct Solution {}

impl Solution {
    pub fn compressed_string(word: String) -> String {
        let mut word_bytes: Vec<u8> = word.bytes().collect();
        let mut compressed: String = String::new();

        let mut count: u8 = 1;
        let mut current_byte: &u8 = word_bytes.first().unwrap();

        for i in 1..word_bytes.len() {
            if count < 9 && current_byte == word_bytes.get(i).unwrap() {
                count += 1;
            } else {
                compressed.push_str(&format!("{}{}", count, current_byte.clone() as char));

                current_byte = word_bytes.get(i).unwrap();
                count = 1;
            }
        }

        compressed.push_str(&format!("{}{}", count, current_byte.clone() as char));

        compressed
    }
}
