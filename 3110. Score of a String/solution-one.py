class Solution:
    def scoreOfString(self, s: str) -> int:
        score = 0

        for idx in range(1, len(s)):
            score += abs(ord(s[idx-1]) - ord(s[idx]))

        return score
