impl Solution {
    pub fn reverse_words(sentence: String) -> String {
        let mut words: Vec<String> = sentence
            .split_whitespace()
            .map(|x| x.to_string())
            .collect();
        words.reverse();
        words.join(" ")
    }
}
