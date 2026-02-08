from collections import defaultdict


class Solution:
    def __init__(self):
        self.memo = defaultdict(str)

    def countAndSay(self, n: int) -> str:
        if n in self.memo:
            return self.memo[n]

        if n == 1:
            return "1"

        prev = self.countAndSay(n - 1)
        result = []
        count = 1

        for i in range(1, len(prev)):
            if prev[i] == prev[i - 1]:
                count += 1
            else:
                result.append(str(count))
                result.append(prev[i - 1])
                count = 1

        result.append(str(count))
        result.append(prev[-1])

        self.memo[n] = ''.join(result)

        return self.memo[n]
