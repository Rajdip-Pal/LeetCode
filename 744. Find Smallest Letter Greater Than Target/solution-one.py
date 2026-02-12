from typing import List


class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        chars = [False]*26

        for ch in letters:
            chars[ord(ch) - ord('a')] = True

        for i in range(ord(target)-ord('a')+1, 26):
            if chars[i]:
                return chr(i+ord('a'))

        return letters[0]
