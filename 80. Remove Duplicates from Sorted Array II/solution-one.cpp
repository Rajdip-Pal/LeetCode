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

        std::vector<int> finalSortedArray;
        finalSortedArray.reserve(nums.size());

        finalSortedArray.push_back(nums.at(0));
        finalSortedArray.push_back(nums.at(1));

        for (int i{2}, j{0}; i < nums.size(); i++)
            if (nums[i] != finalSortedArray[j])
                finalSortedArray.push_back(nums[i]), j++;

        nums.assign(finalSortedArray.begin(), finalSortedArray.end());
        return finalSortedArray.size();
    }
};
