#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

/**
 * Solution 1380. Lucky Numbers in a Matrix
 *
 * @Start
 */

class Solution
{
public:
    std::vector<int> luckyNumbers(std::vector<std::vector<int>> &matrix)
    {
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);

        int rows = matrix.size(), cols = matrix[0].size();
        int temp{};
        std::vector<int> result;
        std::unordered_set<int> minimumInRow;

        for (int i = 0; i < rows; i++)
            minimumInRow.insert(*std::min_element(matrix[i].begin(), matrix[i].end()));

        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
                temp = std::max(temp, matrix[j][i]);
            if (minimumInRow.find(temp) != minimumInRow.end())
                result.push_back(temp);
            temp = 0;
        }

        return result;
    }
};

/**
 * @End
 */

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
