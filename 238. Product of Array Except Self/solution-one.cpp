#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> productExceptSelf(const std::vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int i{}, buffMultiplication{};
        std::vector<int> outPut(nums.size());

        buffMultiplication = 1;
        for (; i < nums.size(); i++)
            outPut[i] = buffMultiplication, buffMultiplication *= nums[i];

        buffMultiplication = 1, i--;
        for (; i >= 0; i--)
            outPut[i] *= buffMultiplication, buffMultiplication *= nums[i];

        return outPut;
    }
};

/**
 * 1 2 3 4  5   6
 *
 * 1 0 0 0  0   0
 *
 * 1 1 2 6  24 120
 *
 * 1 1 2 6 144 120
 * 1 1 2 180 144 120
 * 1 1 240 180 144 120
 */
