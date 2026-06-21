#include <algorithm>
#include <vector>

class Solution
{
public:
    int countUnguarded(const int &m, const int &n, const std::vector<std::vector<int>> &guards, const std::vector<std::vector<int>> &walls)
    {
        enum Cell
        {
            Empty,
            Guard,
            Wall
        };
        std::vector<std::vector<Cell>> grid(m, std::vector<Cell>(n, Cell::Empty));
        std::vector<std::vector<int>>::const_iterator it;
        int up, down, right, left;
        int row, column;
        int unoccupied_cells{};

        for (it = walls.cbegin(); it != walls.cend(); it++)
            grid.at(it->at(0)).at(it->at(1)) = Cell::Wall;

        for (it = guards.cbegin(); it != guards.cend(); it++)
        {
            grid.at(it->front()).at(it->back()) = Cell::Guard;
            row = it->front();
            column = it->back();

            {
                up = row - 1;
                while (up >= 0)
                    if (grid.at(up).at(column) == Cell::Wall)
                        break;
                    else if (grid.at(up).at(column) == Cell::Empty)
                        grid.at(up--).at(column) = Cell::Guard;
                    else
                        up--;
            }
            {
                down = row + 1;
                while (down < m)
                    if (grid.at(down).at(column) == Cell::Wall)
                        break;
                    else if (grid.at(down).at(column) == Cell::Empty)
                        grid.at(down++).at(column) = Cell::Guard;
                    else
                        down++;
            }
            {
                left = column - 1;
                while (left >= 0)
                    if (grid.at(row).at(left) == Cell::Wall)
                        break;
                    else if (grid.at(row).at(left) == Cell::Empty)
                        grid.at(row).at(left--) = Cell::Guard;
                    else
                        left--;
            }
            {
                right = column + 1;
                while (right < n)
                    if (grid.at(row).at(right) == Cell::Wall)
                        break;
                    else if (grid.at(row).at(right) == Cell::Empty)
                        grid.at(row).at(right++) = Cell::Guard;
                    else
                        right++;
            }
        }

        for (int i = 0; i < m; i++)
            unoccupied_cells += std::count(grid.at(i).cbegin(), grid.at(i).cend(), Cell::Empty);

        return unoccupied_cells;
    }
};
