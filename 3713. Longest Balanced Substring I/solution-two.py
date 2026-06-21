from typing import List


class Solution:
    def longestBalanced(self, s: str) -> int:
        N = len(s)
        max_len = 0

        def isBalanced(arr: List[int]) -> bool:
            char_set = set(arr)
            char_set_len = len(char_set)

            return (0 in char_set) if (char_set_len == 2) else (True if char_set_len == 1 else False)

        for start in range(N):
            chars = [0]*26

            if max_len >= N-start:
                break

            for end in range(start, N):
                chars[ord(s[end])-ord('a')] += 1

                if isBalanced(chars):
                    max_len = max(max_len, end-start+1)

        return max_len


s = "zyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxczyxcaabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzzkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjihkjih"

print(len(s))

ans = Solution()
print(
    ans.longestBalanced(s)
)
