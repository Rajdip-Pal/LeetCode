#include <cstring>
#include <iostream>
#include <vector>

class Solution
{
public:
    bool isValidSudoku(const std::vector<std::vector<char>> &board)
    {
        bool checker[9];
        const int row = 9, col = 9;
        const std::pair<short, short> check_points[9] = {{0, 0}, {0, 3}, {0, 6}, {3, 0}, {3, 3}, {3, 6}, {6, 0}, {6, 3}, {6, 6}};

        for (int i = 0, j; i < row; i++)
            for (memset(checker, 0, sizeof(checker)),
                 j = 0;
                 j < col; j++)
                if (board.at(i).at(j) != '.')
                {
                    if (checker[board.at(i).at(j) - '1'])
                        return false;
                    checker[board.at(i).at(j) - '1'] = true;
                }

        for (int i = 0, j; i < col; i++)
            for (memset(checker, 0, sizeof(checker)),
                 j = 0;
                 j < row; j++)
                if (board.at(j).at(i) != '.')
                {
                    if (checker[board.at(j).at(i) - '1'])
                        return false;
                    checker[board.at(j).at(i) - '1'] = true;
                }

        char num;
        for (int i = 0, j, k; i < 9; i++)
            for (memset(checker, 0, sizeof(checker)),
                 j = 0;
                 j < 3; j++)
                for (k = 0; k < 3; k++)
                    if ((num = board.at(check_points[i].first + j).at(check_points[i].second + k)) != '.')
                    {
                        if (checker[num - '1'])
                            return false;
                        checker[num - '1'] = true;
                    }

        return true;
    }
};

auto init = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
