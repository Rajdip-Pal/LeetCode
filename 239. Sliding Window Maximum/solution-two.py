from typing import List
from collections import Counter
import heapq


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        l, r = 0, k - 1

        pq: List[int] = []
        freq = Counter(nums[l:r + 1])

        for num in freq.keys():
            heapq.heappush(pq, -num)

        res = []

        while r < len(nums):
            while -pq[0] not in freq:
                heapq.heappop(pq)

            res.append(-pq[0])
            freq[nums[l]] -= 1
            if freq[nums[l]] == 0:
                del freq[nums[l]]

            if r + 1 < len(nums):
                freq[nums[r + 1]] += 1
                heapq.heappush(pq, -nums[r + 1])

            l += 1
            r += 1

        return res
