#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    static long long countFairPairs(std::vector<int> &nums, const int &lower, const int &upper)
    {
        long long result{};
        std::sort(nums.begin(), nums.end());

        for (std::vector<int>::const_iterator it = nums.cbegin(); it != nums.cend(); ++it)
            result += std::distance(std::lower_bound(it + 1, nums.cend(), lower - *it),
                                    std::upper_bound(it + 1, nums.cend(), upper - *it));

        return result;
    }
};

auto init = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
