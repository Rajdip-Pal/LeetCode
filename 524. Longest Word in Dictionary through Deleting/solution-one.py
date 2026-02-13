from typing import List
from collections import deque, defaultdict
import copy


class Solution:
    def isSubsequence(self, map: defaultdict[str, deque], word: str) -> bool:
        if not word:
            return True

        local_mp = copy.deepcopy(map)
        curr_idx = -1

        for ch in word:
            if ch not in local_mp:
                return False

            if local_mp[ch]:
                while local_mp[ch]:
                    next_idx = local_mp[ch].popleft()
                    if next_idx > curr_idx:
                        curr_idx = next_idx
                        break

                if next_idx < curr_idx:
                    return False
            else:
                return False

        return True

    def generateIndexMap(self, s: str) -> defaultdict[str, deque]:
        mp: defaultdict[str, deque] = defaultdict()

        for i, ch in enumerate(s):
            if ch not in mp:
                mp[ch] = deque()
            mp[ch].append(i)

        return mp

    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        mp = self.generateIndexMap(s)

        res: str = ""

        for ele in dictionary:
            if self.isSubsequence(mp, ele):
                res = res if len(res) > len(ele) or (
                    len(res) == len(ele) and res < ele) else ele

        return res


ans = Solution()

print(ans.findLongestWord("abpcplea",
                          ["", "ab", "acb", "acd", "ale", "apple"]))

# print(ans.isSubsequence(ans.generateIndexMap("abpcplea"), "apple"))

# Worst
