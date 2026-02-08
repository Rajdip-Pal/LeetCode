from collections import defaultdict


class ProductOfNumbers:

    def __init__(self):
        self.products = []
        self.total_product = 1

    def add(self, num: int) -> None:
        self.products.append(
            self.total_product) if num != 0 else self.products.clear()
        self.total_product = self.total_product*num if num != 0 else 1

    def getProduct(self, k: int) -> int:
        return (self.total_product // self.products[-k] if self.products and len(self.products) >= k else 0)

        # Your ProductOfNumbers object will be instantiated and called as such:
        # obj = ProductOfNumbers()
        # obj.add(num)
        # param_2 = obj.getProduct(k)
