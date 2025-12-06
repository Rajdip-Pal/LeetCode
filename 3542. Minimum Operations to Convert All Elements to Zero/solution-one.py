from typing import List


class Solution:
    def minOperations(self, nums: List[int]) -> int:
        stack: List[int] = []
        result: int = 0
        for n in nums:
            while stack and n < stack[-1]:
                stack.pop()
                result += 1
            if n > 0 and (not stack or n > stack[-1]):
                stack.append(n)
        result += len(stack)
        return result
