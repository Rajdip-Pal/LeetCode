#include <cstdint>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int missingNumber(std::vector<int> &nums)
    {
        std::stable_sort(nums.begin(), nums.end());
        for (int i = 1; i <= nums.size(); i++)
            if (!std::binary_search(nums.cbegin(), nums.cend(), i))
                return i;
        return INT32_MIN;
    }
};
