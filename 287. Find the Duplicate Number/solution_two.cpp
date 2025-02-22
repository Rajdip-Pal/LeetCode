#include <vector>

class Solution
{
public:
    int findDuplicate(const std::vector<int> &nums)
    {
        std::vector<bool> __record(nums.size(), false);
        for (int i = 0; i < nums.size(); i++)
        {
            if (__record.at(nums.at(i)))
                return nums.at(i);
            __record.at(nums.at(i)) = true;
        }
        return 0;
    }
};
