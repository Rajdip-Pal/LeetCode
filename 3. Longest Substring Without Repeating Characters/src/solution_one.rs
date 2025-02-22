pub struct Solution {}

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let sentence: &[u8] = s.as_bytes();
        let mut max_length: usize = 0;
        let (mut left, mut right): (usize, usize) = (0, 0);
        let mut char_set: std::collections::HashSet<&u8> = std::collections::HashSet::new();

        while right < sentence.len() {
            if char_set.contains(sentence.get(right).unwrap()) {
                char_set.remove(sentence.get(left).unwrap());
                left += 1;
            } else {
                char_set.insert(sentence.get(right).unwrap());
                right += 1;
                max_length = max_length.max(right - left);
            }
        }

        max_length as i32
    }
}
