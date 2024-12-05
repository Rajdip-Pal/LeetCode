#include <vector>

using ::std::vector;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        int di[4] = {0, 1, 0, -1};
        int dj[4] = {1, 0, -1, 0};

        auto dfs = [&](auto &&self, int row, int column) -> void
        {
            if (!visited[row][column])
            {
                visited[row][column] = true;
                if (row > 0 && grid[row - 1][column] == '1')
                    self(self, row - 1, column);
                if (column > 0 and grid[row][column - 1] == '1')
                    self(self, row, column - 1);
                if (row < grid.size() - 1 and grid[row + 1][column] == '1')
                    self(self, row + 1, column);
                if (column < grid[0].size() - 1 and grid[row][column + 1] == '1')
                    self(self, row, column + 1);
            }
        };

        int islands = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    dfs(dfs, i, j);
                    islands++;
                }
            }
        }

        return islands;
    }
};
