from typing import List
from collections import defaultdict


class Solution:
    precompute: defaultdict[int, List[str]] = defaultdict()

    def __init__(self):
        set_bits = [0]*60

        def count_set_bits(n: int):
            count = 0
            while n > 0:
                n, count = n & (n-1), count + 1
            return count

        for i in range(60):
            set_bits[i] = count_set_bits(i)

        for i in range(11):
            self.precompute[i] = []

        for i in range(12):
            for j in range(60):
                self.precompute[set_bits[i]+set_bits[j]].append(f"{i}:{j:02d}")

    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        return self.precompute[turnedOn]
