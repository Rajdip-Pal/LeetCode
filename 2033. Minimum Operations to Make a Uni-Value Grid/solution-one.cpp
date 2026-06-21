#include <algorithm>
#include <vector>

class Solution
{
public:
    int minOperations(std::vector<std::vector<int>> &grid, int x)
    {
        int result = 0;
        std::vector<int> numsArray;

        for (int row = 0; row < grid.size(); row++)
            for (int col = 0; col < grid[0].size(); col++)
                numsArray.push_back(grid[row][col]);

        size_t length = numsArray.size();
        std::nth_element(numsArray.begin(), numsArray.begin() + length / 2, numsArray.end());

        int finalCommonNumber = numsArray[length / 2];
        int rem = finalCommonNumber % x;

        for (size_t i{}, j{length - 1}; i < j; i++, j--)
            if ((numsArray[j] % x == numsArray[i] % x) and (numsArray[i] % x == rem))
                result += (numsArray[j] - numsArray[i]) / x;
            else
                return -1;

        return result;
    }
};
