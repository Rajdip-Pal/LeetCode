from collections import defaultdict
from types import List


class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        unique_nums: defaultdict[int, int] = defaultdict(int)

        for n in nums:
            if unique_nums[n]:
                return n
            else:
                unique_nums[n] += 1

        return -1  # This line should never be reached given the problem constraints
