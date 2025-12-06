class Solution:

    INT32_MAX = 2**31 - 1
    INT32_MIN = -2**31

    def myAtoi(self, s: str) -> int:
        res: int = 0
        s = s.strip()
        sign = 1

        if not s:
            return 0

        if s[0] not in "+-" and not s[0].isdigit():
            return 0

        if s[0] in "+-":
            sign = 1 if s[0] == "+" else -1
            s = s[1:]

        res *= sign

        for digit in s:
            if digit.isnumeric():
                res = res * 10 + sign * int(digit)
            else:
                break

        if sign == 1 and res > self.INT32_MAX:
            return self.INT32_MAX
        if sign == -1 and res < self.INT32_MIN:
            return self.INT32_MIN

        return res
