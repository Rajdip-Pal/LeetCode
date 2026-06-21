#include <unordered_set>
#include <vector>

class Solution
{
public:
    int findFinalValue(std::vector<int> &nums, int original)
    {
        std::unordered_set<int> nums_map(nums.begin(), nums.end());
        while (nums_map.find(original) != nums_map.end())
            original *= 2;
        return original;
    }
};
