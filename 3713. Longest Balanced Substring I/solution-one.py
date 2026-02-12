from typing import List


class Solution:
    def longestBalanced(self, s: str) -> int:
        N = len(s)
        max_len = 0

        def isBalanced(arr: List[int]) -> bool:
            count = 0

            for c in arr:
                if count == 0 and c != 0:
                    count = c
                elif c != 0 and count != c:
                    return False

            return True

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
