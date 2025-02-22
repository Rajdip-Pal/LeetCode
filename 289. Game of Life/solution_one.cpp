#include <vector>

class Solution
{
public:
    void gameOfLife(std::vector<std::vector<int>> &board)
    {
        //  0 -> dead, 1 -> Alive;
        /*
        Any live cell with fewer than two live neighbors dies as if caused by under-population.
        Any live cell with two or three live neighbors lives on to the next generation.
        Any live cell with more than three live neighbors dies, as if by over-population.

        Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
         */

        /*
            Less runtime;

            1. Create a copy of the board
            2. Iterate over the board
            3. For each cell, count the number of live neighbors
            4. If the cell is live and has less than two or more than three live neighbors, set the cell to dead
            5. If the cell is dead and has exactly three live neighbors, set the cell to live
            6. Copy the new board to the original board
        */

        int alive{};
        int row = board.size(), column = board.front().size();
        std::vector<std::vector<int>> newBoard(row, std::vector<int>(column));

        for (int i = 0, j; i < row; i++)
            for (j = 0; j < column; j++, alive = 0)
            {
                if (i > 0)
                {
                    if (board[i - 1][j] == 1)
                        alive++;
                    if (j > 0 && board[i - 1][j - 1] == 1)
                        alive++;
                    if (j < column - 1 && board[i - 1][j + 1] == 1)
                        alive++;
                }

                if (i < row - 1)
                {
                    if (board[i + 1][j] == 1)
                        alive++;
                    if (j > 0 && board[i + 1][j - 1] == 1)
                        alive++;
                    if (j < column - 1 && board[i + 1][j + 1] == 1)
                        alive++;
                }

                if (j > 0 && board[i][j - 1] == 1)
                    alive++;
                if (j < column - 1 && board[i][j + 1] == 1)
                    alive++;

                if (board.at(i).at(j) == 1 and (alive == 2 or alive == 3))
                    newBoard[i][j] = 1;
                else if (board.at(i).at(j) == 0 and alive == 3)
                    newBoard[i][j] = 1;
            }
        board = newBoard;
    }
};
