#include <iostream>
#include <vector>

class Solution
{
public:
    void setZeroes(std::vector<std::vector<int>> &matrix)
    {
        std::vector<bool> rows(matrix.size()), columns(matrix.front().size());

        for (int i = 0, j; i < matrix.size(); i++)
            for (j = 0; j < matrix.front().size(); j++)
                if (matrix.at(i).at(j) == 0)
                    rows.at(i) = true, columns.at(j) = true;

        std::vector<bool>::const_iterator it;

        for (it = rows.cbegin(); it != rows.cend(); it++)
            if (*it)
                matrix.at(it - rows.cbegin()).assign(matrix.front().size(), 0);

        for (it = columns.begin(); it != columns.end(); it++)
            if (*it)
            {
                for (int i = 0; i < matrix.size(); i++)
                    matrix.at(i).at(it - columns.cbegin()) = 0;
            }
    }
};

auto init = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
