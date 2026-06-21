#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

class Solution
{
public:
    int maxMoves(const std::vector<std::vector<int>> &grid)
    {
        int rows = grid.size(), columns = grid.front().size();
        int maximumPossibleMoves{};
        std::vector<std::vector<int>> dp(rows, std::vector<int>(columns, 0));

        for (int j = columns - 2; j >= 0; j--)
            for (int i = 0; i < rows; i++)
            {
                if (i > 0 and grid[i][j] < grid[i - 1][j + 1])
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j + 1] + 1);

                if (grid[i][j] < grid[i][j + 1])
                    dp[i][j] = std::max(dp[i][j], dp[i][j + 1] + 1);

                if (i < rows - 1 and grid[i][j] < grid[i + 1][j + 1])
                    dp[i][j] = std::max(dp[i][j], dp[i + 1][j + 1] + 1);
            }

        for (int i = 0; i < rows; i++)
            maximumPossibleMoves = std::max(maximumPossibleMoves, dp[i][0]);

        return maximumPossibleMoves;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
