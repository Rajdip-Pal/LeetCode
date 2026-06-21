#include <vector>
#include <unordered_set>

class Solution
{
public:
    int findDuplicate(const std::vector<int> &nums)
    {
        std::unordered_set<int> __record;
        for (int i = 0; i < nums.size(); i++)
        {
            if (__record.find(nums.at(i)) != __record.end())
                return nums.at(i);
            __record.insert(nums.at(i));
        }
        return 0;
    }
};
