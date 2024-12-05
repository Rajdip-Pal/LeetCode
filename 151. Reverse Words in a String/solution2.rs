impl Solution {
    pub fn reverse_words(sentence: String) -> String {
        sentence
            .split_whitespace()
            .rev()
            .map(|x| x.to_string())
            .collect::<Vec<String>>()
            .join(" ")
    }
}
