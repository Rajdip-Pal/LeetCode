#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>> &grid, int k)
    {
        const int m = grid.size();
        const int n = m == 0 ? 0 : grid[0].size();

        const int total_elements = m * n;
        int matrix[total_elements];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                matrix[(i * m + j + k) % total_elements] = grid[i][j];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                grid[i][j] = matrix[i * m + j];

        return grid;
    }
};