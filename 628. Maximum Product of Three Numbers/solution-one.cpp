#include <vector>
#include <algorithm>

class Solution
{
public:
    int maximumProduct(std::vector<int> &nums)
    {
        const int n = nums.size();
        std::sort(nums.begin(), nums.end());

        int option_a = nums[0] * nums[1] * nums[n - 1];
        int option_b = nums[n - 1] * nums[n - 2] * nums[n - 3];

        return std::max(option_a, option_b);
    }
};