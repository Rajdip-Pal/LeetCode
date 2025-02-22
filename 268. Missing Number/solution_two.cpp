#include <numeric>
#include <vector>

class Solution
{
public:
    int missingNumber(const std::vector<int> &nums)
    {
        return (((nums.size()) * (nums.size() + 1)) / 2) - std::accumulate(nums.cbegin(), nums.cend(), 0);
    }
};
