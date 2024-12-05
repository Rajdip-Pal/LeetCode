#![allow(dead_code, unused)]

pub struct Solution {}

impl Solution {
    pub fn is_subsequence(sequence: String, main_string: String) -> bool {
        let (mut main_string_pointer, mut subsequence_pointer): (usize, usize) = (0, 0);
        let main_string_bytes = main_string.bytes().collect::<Vec<u8>>();
        let subsequence_bytes = sequence.bytes().collect::<Vec<u8>>();

        while main_string_pointer < main_string.len() && subsequence_pointer < sequence.len() {
            if main_string_bytes[main_string_pointer] == subsequence_bytes[subsequence_pointer] {
                subsequence_pointer += 1;
            }
            main_string_pointer += 1;
        }

        if subsequence_pointer == sequence.len() {
            true
        } else {
            false
        }
    }
}
