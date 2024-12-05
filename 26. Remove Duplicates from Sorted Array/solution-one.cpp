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

        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == nums[i - 1])
                nums.erase(nums.begin() + i--);
        return nums.size();
    }
};
