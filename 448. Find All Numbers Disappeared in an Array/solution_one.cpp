#include <vector>

/*
    CODE START
*/

class Solution
{
    static bool num_collection[100001];

public:
    std::vector<int> findDisappearedNumbers(const std::vector<int> &nums)
    {
        __builtin_memset(num_collection, false, nums.size() + 1);
        std::vector<int> result;

        for (int i = 0; i < nums.size(); i++)
            num_collection[nums[i]] = true;

        for (int i = 1; i <= nums.size(); i++)
            if (!num_collection[i])
                result.push_back(i);

        return result;
    }
};

bool Solution::num_collection[100001];

/*
    CODE END
*/
