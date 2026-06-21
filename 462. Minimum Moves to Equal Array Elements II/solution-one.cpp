#include <algorithm>
#include <vector>

class Solution
{
public:
    int minMoves2(std::vector<int> &nums)
    {
        int ans{};
        std::nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        for (int i{}; i < nums.size() / 2; i++)
            ans += nums[nums.size() - i - 1] - nums[i];
        return ans;
    }
};
