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
                for (int i = 0; i < 4; i++)
                {
                    int new_row = row + di[i];
                    int new_column = column + dj[i];
                    if ((new_row >= 0 && new_row < grid.size()) and
                        (new_column >= 0 && new_column < grid[0].size()) and
                        grid[new_row][new_column] == '1')

                        self(self, new_row, new_column);
                }
            }
        };

        int islands = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == '1' && !visited[i][j])
                    dfs(dfs, i, j),
                        islands++;

        return islands;
    }
};
