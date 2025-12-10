from typing import List
from collections import Counter


class Solution:
    __MOD = 10**9 + 7

    def specialTriplets(self, nums: List[int]) -> int:
        freqPrev: Counter = Counter()
        freqNext: Counter = Counter(nums)

        result: int = 0

        n: int = len(nums)

        freqPrev[nums[0]] += 1
        freqNext[nums[0]] -= 1
        for i in range(1, n):
            freqNext[nums[i]] -= 1

            result += freqPrev[nums[i]*2] * freqNext[nums[i]*2]
            result %= self.__MOD

            freqPrev[nums[i]] += 1

        return result
