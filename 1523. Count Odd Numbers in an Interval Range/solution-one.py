class Solution:
    def countOdds(self, low: int, high: int) -> int:
        count: int = 0

        if low & 1 == 1:
            low += 1
            count += 1

        if high & 1 == 1:
            high -= 1
            count += 1

        count += (high - low) // 2

        return count
