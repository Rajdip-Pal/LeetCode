#include <algorithm>
#include <vector>

class Solution
{
public:
    int maximumBeauty(std::vector<int> &nums, const int &k)
    {
        std::sort(nums.begin(), nums.end());
        int r{}, l{};
        for (r = 0; r < nums.size(); r++)
            nums.at(r) - nums.at(l) > 2 * k ? l++ : 0;
        return r - l;
    }
};
