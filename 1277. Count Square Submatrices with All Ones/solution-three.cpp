#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int countSquares(std::vector<std::vector<int>> &matrix)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int result{}, i{}, j{};

        for (i = 0; i < matrix.size(); i++)
            result += matrix[i][0];

        for (i = 1; i < matrix[0].size(); i++)
            result += matrix[0][i];

        for (i = 1; i < matrix.size(); i++)
            for (j = 1; j < matrix[0].size(); result += matrix[i][j++])
                if (matrix[i][j] != 0)
                    matrix[i][j] = 1 + std::min({matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]});

        return result;
    }
};
