from pyparsing import List
import math


class Solution:
    def maximumEnergy(self, energy: List[int], k: int) -> int:
        N = len(energy)
        power = [0]*k

        for i in range(N//k + 1):
            for j in range(k):
                power[j] = (
                    max(energy[j+i*k], power[j] + energy[j+i*k])
                    if j+i*k < N
                    else power[j]
                )

        return max(power)
