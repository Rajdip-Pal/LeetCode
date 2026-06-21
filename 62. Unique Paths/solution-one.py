class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        total_paths = 1

        if m > n:
            m, n = n, m

        # Total steps m+n-2
        # need to select either m-1 or n-1 step so (m+n-2)C(m-1)
        # so (n-1+k)C(k) where k = m-1
        # now (n-1+k)C(k) = (...) this simplifies to this =>

        # for k in range(1, m):
        #     total_paths = total_paths * (1 + (n-1)/k)
        # Ok don't use this has a precesion problem

        for k in range(1, m):
            total_paths = total_paths * (n-1+k) / k

        return int(total_paths)
