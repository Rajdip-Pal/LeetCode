#include <iostream>
#include <vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        if (nums.size() < 3)
            return nums.size();

        int j{2};
        for (int i{2}; i < nums.size(); i++)
            if (nums[i] != nums[j - 2])
                nums[j++] = nums[i];

        return j;
    }
};
