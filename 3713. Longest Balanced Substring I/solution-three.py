from typing import List
from collections import defaultdict


class Solution:
    def longestBalanced(self, s: str) -> int:
        N = len(s)
        max_len = 0

        for start in range(N):
            chars = defaultdict(int)

            if max_len >= N-start:
                break

            for end in range(start, N):
                chars[s[end]] += 1
                if len(set(chars.values())) == 1:
                    max_len = max(max_len, end-start+1)

        return max_len


s = "zyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxcaabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzzkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjih"

print(len(s))

ans = Solution()
print(
    ans.longestBalanced(s)
)
