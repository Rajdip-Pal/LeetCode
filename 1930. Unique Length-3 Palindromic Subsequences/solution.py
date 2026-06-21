from collections import Counter


class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        res: set = set()

        left: set = set()
        right: Counter = Counter(s)

        for ch in s:
            right[ch] -= 1
            if right[ch] == 0:
                del right[ch]

            if left and right:
                res.update([k + ch + k for k in left if k in right])

            left.add(ch)

        print(res)
        return len(res)
