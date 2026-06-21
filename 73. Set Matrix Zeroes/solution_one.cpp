#include <iostream>
#include <unordered_set>
#include <vector>

class Solution
{
public:
    void setZeroes(std::vector<std::vector<int>> &matrix)
    {
        std::unordered_set<int> rows, columns;

        for (int i = 0, j; i < matrix.size(); i++)
            for (j = 0; j < matrix.front().size(); j++)
                if (matrix.at(i).at(j) == 0)
                    rows.insert(i), columns.insert(j);

        std::unordered_set<int>::const_iterator it;

        for (it = rows.begin(); it != rows.end(); it++)
            matrix.at(*it).assign(matrix.front().size(), 0);

        for (it = columns.begin(); it != columns.end(); it++)
            for (int i = 0; i < matrix.size(); i++)
                matrix.at(i).at(*it) = 0;
    }
};

auto init = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
