from collections import defaultdict
from typing import DefaultDict, List


class Solution:
    def numberOfWays(self, s: str) -> int:
        prefixMap: DefaultDict[str, int] = defaultdict(int)
        suffixMap: DefaultDict[str, int] = defaultdict(int)

        for char in s:
            suffixMap[char] += 1

        result: int = 0

        for char in s:
            suffixMap[char] -= 1

            if char == "0":
                result += prefixMap["1"] * suffixMap["1"]
            else:
                result += prefixMap["0"] * suffixMap["0"]

            prefixMap[char] += 1

        return result
