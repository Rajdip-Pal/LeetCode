from typing import List


class Solution:
    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:

        def is_valid_chars(code: str) -> bool:
            return len(code) > 0 and all(c.isalnum() or c == '_' for c in code)

        valid_coupons_in_each_bussinessLine = {
            "electronics": [],
            "grocery": [],
            "pharmacy": [],
            "restaurant": []
        }

        for c, b, a in zip(code, businessLine, isActive):
            if is_valid_chars(c) and b in valid_coupons_in_each_bussinessLine.keys() and a:
                valid_coupons_in_each_bussinessLine[b].append(c)

        result = []
        for b in sorted(valid_coupons_in_each_bussinessLine.keys()):
            result.extend(sorted(valid_coupons_in_each_bussinessLine[b]))

        return result
