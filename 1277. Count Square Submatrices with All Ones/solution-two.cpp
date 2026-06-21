#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int countSquares(const std::vector<std::vector<int>> &matrix)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int rows = matrix.size(), columns = matrix.front().size();
        int result{};
        std::vector<std::vector<int>> dp(rows, std::vector<int>(columns, 0));

        for (int i = 0; i < rows; i++)
            dp[i][0] = matrix[i][0],
            result += matrix[i][0];

        for (int i = 1; i < columns; i++)
            dp[0][i] = matrix[0][i],
            result += matrix[0][i];

        for (int i = 1; i < rows; i++)
            for (int j = 1; j < columns; j++)
                if (matrix[i][j])
                    dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}),
                    result += dp[i][j];

        return result;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
