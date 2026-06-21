#include <vector>

class Solution
{
public:
    int singleNonDuplicate(const std::vector<int> &nums)
    {
        int ans = nums.front();
        for (int i = 1; i < nums.size(); i++)
            ans = (ans xor nums[i]);

        return ans;
    }
};
