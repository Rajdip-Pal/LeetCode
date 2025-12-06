#include <vector>

class Solution
{
public:
    bool kLengthApart(std::vector<int> &nums, int k)
    {
        for (int i = 0, prev = -1; i < nums.size(); i++)
            if (1 == nums[i])
            {
                if (prev >= 0 && i - prev - 1 < k)
                    return false;
                prev = i;
            }
        return true;
    }
};
