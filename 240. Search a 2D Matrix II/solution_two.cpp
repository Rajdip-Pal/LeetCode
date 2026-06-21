#include <vector>

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, const int &target)
    {
        int row = 0, col = matrix.front().size() - 1;

        while (row < matrix.size() and col > -1)
            if (target == matrix.at(row).at(col))
            {
                matrix.clear();
                return true;
            }
            else if (target > matrix.at(row).at(col))
                row++;
            else
                col--;

        return false;
    }
};
