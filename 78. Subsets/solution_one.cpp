#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> subsets(const std::vector<int> &nums)
    {
        int arrr_size = nums.size();
        int total = 1 << (arrr_size);
        std::vector<std::vector<int>> subsets;
        std::vector<int> subset;

        for (int i = 0; i < total; i++)
        {
            subset.clear();
            for (int j = 0; j < arrr_size; j++)
                if (i & (1 << j))
                    subset.push_back(nums[j]);
            subsets.push_back(subset);
        }

        return subsets;
    }
};
