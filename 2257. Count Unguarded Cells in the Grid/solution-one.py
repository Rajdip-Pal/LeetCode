from pyparsing import List
from enum import Enum
from collections import defaultdict


class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:

        guards_row = defaultdict(list)
        guards_col = defaultdict(list)

        walls_row = defaultdict(list)
        walls_col = defaultdict(list)

        for guard in guards:
            guards_row[guard[0]].append(guard[1])
            guards_col[guard[1]].append(guard[0])

        for wall in walls:
            walls_row[wall[0]].append(wall[1])
            walls_col[wall[1]].append(wall[0])

        print(guards_row, guards_col)
        print(walls_row, walls_col)

        return 0
