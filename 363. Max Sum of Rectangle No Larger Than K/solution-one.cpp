#include <vector>
#include <limits>
#include <iostream>

class Solution
{
public:
    int maxSumSubmatrix(std::vector<std::vector<int>> &matrix, int k)
    {
        const int m = matrix.size();
        const int n = matrix[0].size();

        int dp[m][n];

        dp[0][0] = matrix[0][0];
        for (int i = 1; i < m; i++)
            dp[i][0] = dp[i - 1][0] + matrix[i][0];
        for (int j = 1; j < n; j++)
            dp[0][j] = dp[0][j - 1] + matrix[0][j];
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i][j];

        int max = (unsigned)__INT_MAX__ + 1;
        for (int r1 = 0; r1 < m; r1++)
            for (int r2 = r1; r2 < m; r2++)
                for (int c1 = 0; c1 < n; c1++)
                    for (int c2 = c1; c2 < n; c2++)
                    {
                        const int a = r1 > 0 && c1 > 0 ? dp[r1 - 1][c1 - 1] : 0;
                        const int b = r1 > 0 ? dp[r1 - 1][c2] : 0;
                        const int c = dp[r2][c2];
                        const int d = c1 > 0 ? dp[r2][c1 - 1] : 0;
                        const int sum = c - b - d + a;

                        if (sum <= k)
                        {
                            max = std::max(sum, max);
                            if (max == k)
                                break;
                        }
                    }

        return max;
    }
};

int main()
{
    Solution s = Solution();
    auto v = std::vector<std::vector<int>>(10, std::vector<int>(5));
    s.maxSumSubmatrix(v, 10);
    return 0;
}
