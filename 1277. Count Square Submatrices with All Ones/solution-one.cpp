#include <iostream>
#include <vector>

class Solution
{
    void find_result(const std::vector<std::vector<int>> &matrix, int &possibleSquareMatrix)
    {
        int countElement{};
        std::vector<int> temp(matrix.front().size(), 0);

        for (int group = 1; group <= matrix.size(); group++)
        {
            for (int traverse = 0; traverse <= matrix.size() - group; traverse++)
            {
                for (int i = traverse; i < traverse + group; i++)
                    for (int j = 0; j < temp.size(); j++)
                        temp[j] += matrix[i][j];

                for (int i = 0; i < temp.size(); i++)
                {
                    if (temp[i] == group)
                        countElement++;
                    else
                    {
                        if (countElement >= group)
                            possibleSquareMatrix += countElement - group + 1;
                        countElement = 0;
                    }
                }
                if (countElement >= group)
                    possibleSquareMatrix += countElement - group + 1;
                countElement = 0;
                temp.assign(matrix.front().size(), 0);
            }
        }
    }

public:
    int countSquares(std::vector<std::vector<int>> &matrix)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int result{};
        find_result(matrix, result);
        return result;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
