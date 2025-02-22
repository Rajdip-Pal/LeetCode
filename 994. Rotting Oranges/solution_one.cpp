#include <queue>
#include <vector>

using ::std::pair;
using ::std::queue;
using ::std::vector;

class Solution
{
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    void bfs(queue<pair<int, int>> q, vector<vector<int>> &grid, vector<vector<bool>> &visited, int &time, int m, int n, int &fresh)
    {
        auto is_valid = [&](const int &x, const int &y) -> bool
        {
            return (x >= 0 && x < m && y >= 0 && y < n);
        };

        while (!q.empty() and fresh > 0)
        {
            int level = q.size();
            time++;
            while (level--)
            {
                for (int i = 0; i < 4; i++)
                {
                    int nx = q.front().first + dx[i];
                    int ny = q.front().second + dy[i];

                    if (is_valid(nx, ny) and !visited[nx][ny] and
                        grid[nx][ny] == 1)
                    {
                        visited[nx][ny] = true;
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
                q.pop();
            }
        }
    }

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        int fresh = 0;
        int total_time = 0;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 2)
                {
                    visited[i][j] = true;
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        bfs(q, grid, visited, total_time, rows, cols, fresh);

        return fresh > 0 ? -1 : total_time;
    }
};
