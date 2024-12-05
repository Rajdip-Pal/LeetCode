#include <algorithm>
#include <vector>

class Solution
{
public:
    void rotate(std::vector<std::vector<int>> &matrix)
    {
        int row = matrix.size();
        for (int i = 0; i < row; i++)
            for (int j = i; j < row; j++)
                std::swap(matrix[i][j], matrix[j][i]);

        for (int i = 0; i < row; i++)
            std::reverse(matrix[i].begin(), matrix[i].end());
    }
};
