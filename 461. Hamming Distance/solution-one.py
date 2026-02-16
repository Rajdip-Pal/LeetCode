class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        bin_x, bin_y = '{:032b}'.format(x), '{:032b}'.format(y)

        count = 0
        for i in range(32):
            if bin_x[i] != bin_y[i]:
                count += 1

        return count
