from typing import List


class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:

        total_distance = 0

        bin_nums = []
        for n in nums:
            bin_nums.append("{:032b}".format(n))

        for i in range(32):
            zeros, ones = 0, 0
            for b in bin_nums:
                total_distance, zeros, ones = (
                    (total_distance + ones, zeros + 1, ones)
                    if b[i] == "0"
                    else (total_distance + zeros, zeros, ones + 1)
                )

        return total_distance
