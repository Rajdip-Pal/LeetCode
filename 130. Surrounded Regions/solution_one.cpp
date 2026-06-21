#include <vector>

#define vvb vector<vector<bool>>
#define vvc vector<vector<char>>

using ::std::vector;

class Solution
{
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    void dfs(int row, int col, vvb &vis, vvc &board, int n, int m)
    {
        vis[row][col] = true;

        auto isValid = [&](int x, int y) -> bool
        {
            return x >= 0 && x < n && y >= 0 && y < m;
        };

        for (int k = 0; k < 4; k++)
        {
            int tmpRow = row + dx[k];
            int tmpCol = col + dy[k];

            if (isValid(tmpRow, tmpCol) && !vis[tmpRow][tmpCol] && board[tmpRow][tmpCol] == 'O')
            {
                dfs(tmpRow, tmpCol, vis, board, n, m);
            }
        }
    }
    void solve(vector<vector<char>> &board)
    {
        int n = board.size(), m = board[0].size();
        vvb vis(n, vector<bool>(m, false));

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (!vis[row][col] && board[row][col] == 'O' && (row == 0 || row == n - 1 || col == 0 || col == m - 1))
                {
                    dfs(row, col, vis, board, n, m);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};
