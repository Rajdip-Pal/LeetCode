#include <vector>

class Solution
{
public:
    int maxProduct(std::vector<int> &nums)
    {
        int max_elem_indexes[2] = {0, 1};
        if (nums[1] > nums[0])
        {
            max_elem_indexes[0] = 1;
            max_elem_indexes[1] = 0;
        }

        const auto insert = [&](int idx) -> void
        {
            if (nums[idx] >= nums[max_elem_indexes[0]])
            {
                max_elem_indexes[1] = max_elem_indexes[0];
                max_elem_indexes[0] = idx;
            }
            else if (nums[idx] > nums[max_elem_indexes[1]])
            {
                max_elem_indexes[1] = idx;
            }
        };

        for (int i = 2; i < nums.size(); i++)
            insert(i);

        return (nums[max_elem_indexes[0]] - 1) * (nums[max_elem_indexes[1]] - 1);
    }
};