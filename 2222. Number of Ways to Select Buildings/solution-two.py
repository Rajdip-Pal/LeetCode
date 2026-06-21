from collections import defaultdict
from typing import DefaultDict, List


class Solution:
    def numberOfWays(self, s: str) -> int:
        # first is for prev and second is for next
        restaurant: list[int, int] = [0, 0]
        office: list[int, int] = [0, 0]

        for char in s:
            if char == "0":
                office[1] += 1
            else:
                restaurant[1] += 1

        result: int = 0

        for char in s:

            if char == "0":
                office = [office[0] + 1, office[1] - 1]
                result += restaurant[0] * restaurant[1]
            else:
                restaurant = [restaurant[0] + 1, restaurant[1] - 1]
                result += office[0] * office[1]

        return result
