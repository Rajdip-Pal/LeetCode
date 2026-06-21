from typing import List
from collections import Counter


class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        def validity(word: str, map: Counter):
            nonlocal score

            wordScore = 0
            newMap = map.copy()

            for ch in word:
                if newMap[ch] < 1:
                    return (False, map, 0)
                wordScore += score[ord(ch)-ord('a')]
                newMap[ch] -= 1

            return (True, newMap, wordScore)

        def getScore(start, end, map, score):
            if start > end:
                return score

            word_data = validity(words[start], map)

            if word_data[0]:
                return max(getScore(start+1, end, word_data[1], score + word_data[2]), getScore(start+1, end, map, score))
            else:
                return getScore(start+1, end, map, score)

        return getScore(0, len(words)-1, Counter(letters), 0)


a = Solution()
print(
    a.maxScoreWords(
        ["dog", "cat", "dad", "good"],
        ["a", "a", "c", "d", "d", "d", "g", "o", "o"],
        [1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    )
)
