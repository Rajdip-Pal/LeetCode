#include <algorithm>
#include <vector>

class Solution
{
public:
    int maximumBeauty(std::vector<int> &nums, const int &k)
    {
        std::sort(nums.begin(), nums.end());
        int length{}, i{}, j{};
        while (i < nums.size() and j < nums.size())
            (nums[i] <= nums[j] + 2 * k) ? i++ : j++,
                length = std::max(length, i - j);
        return length;
    }
};
