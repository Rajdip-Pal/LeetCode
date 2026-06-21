from typing import List


class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        if len(nums) <= 3:
            return False

        p = (0, 0)
        q = (0, 0)

        for i in range(1, len(nums) - 1):
            if nums[i] == nums[i-1] or nums[i] == nums[i+1]:
                return False
            if nums[i] > nums[i - 1] and nums[i] > nums[i + 1]:
                p = (i, p[1] + 1)
            if nums[i] < nums[i - 1] and nums[i] < nums[i + 1]:
                q = (i, q[1] + 1)

        return True if p[1] == 1 and q[1] == 1 and p[0] < q[0] else False
