#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <iomanip>

class Solution
{
public:
    int maxMoves(const std::vector<std::vector<int>> &grid)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        const int rows = grid.size(), columns = grid.front().size();
        int maximumPossibleMoves{};
        int **dp = (int **)calloc(rows, sizeof(int *));

        for (int i = 0; i < rows; i++)
            dp[i] = (int *)calloc(columns, sizeof(int));

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                dp[i][j] = 0;

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

        for (int i = 0; i < rows; i++)
            free(dp[i]);
        free(dp);

        return maximumPossibleMoves;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
