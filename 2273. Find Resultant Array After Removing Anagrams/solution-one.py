from typing import List


class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        sorted_words: List[str] = [sorted(word) for word in words]
        result: List[str] = []

        for i in range(len(words)):
            if not result or sorted_words[i] != sorted_words[i - 1]:
                result.append(words[i])

        return result
