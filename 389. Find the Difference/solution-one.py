class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        bit_mask = [0] * 26

        for char in s:
            idx = ord(char) - ord('a')
            bit_mask[idx] += 1

        for char in t:
            idx = ord(char) - ord('a')
            bit_mask[idx] -= 1
            if bit_mask[idx] < 0:
                return char

        # This line should never be reached since t is guaranteed to have one extra character.
        return ''

# Example usage:
