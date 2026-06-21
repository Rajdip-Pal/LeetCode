#include <set>
#include <vector>

class Solution
{
public:
    int findFinalValue(std::vector<int> &nums, int original)
    {
        std::set<int> nums_set(nums.begin(), nums.end());
        while (nums_set.find(original) != nums_set.end())
            original *= 2;
        return original;
    }
};
