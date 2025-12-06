class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        uniques: set = set(s)
        res: int = 0
        for ch in uniques:
            first = s.find(ch)
            last = s.rfind(ch)

            res += len(set(s[first+1:last]))
        return res
