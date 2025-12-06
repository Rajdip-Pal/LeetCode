from typing import List


class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        row = [1]

        for _ in range(1, rowIndex + 1):
            row = [1] + [row[j-1] + row[j]
                         for j in range(1, len(row))] + [1]

        return row
