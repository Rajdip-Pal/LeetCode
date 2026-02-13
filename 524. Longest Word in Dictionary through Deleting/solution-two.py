from typing import List
from collections import defaultdict
import bisect


class Solution:
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        pos = defaultdict(list)

        # build index map
        for i, ch in enumerate(s):
            pos[ch].append(i)

        def isSubsequence(word: str) -> bool:
            curr = -1
            for ch in word:
                if ch not in pos:
                    return False

                idx_list = pos[ch]
                j = bisect.bisect_right(idx_list, curr)

                if j == len(idx_list):
                    return False

                curr = idx_list[j]

            return True

        best = ""
        for word in dictionary:
            if len(word) > len(best) or (len(word) == len(best) and word < best):
                if isSubsequence(word):
                    best = word

        return best
