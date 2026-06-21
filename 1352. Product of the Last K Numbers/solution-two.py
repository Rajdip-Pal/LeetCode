from collections import defaultdict


class ProductOfNumbers:
    def __init__(self):
        self.pre_prod = [1]

    def add(self, num: int) -> None:
        if num:
            self.pre_prod.append(self.pre_prod[-1] * num)
        else:
            self.pre_prod = [1]

    def getProduct(self, k: int) -> int:
        return (self.pre_prod[-1] // self.pre_prod[-k-1] if len(self.pre_prod) > k else 0)
