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

        std::vector<int> resultVector;
        resultVector.reserve(nums.size());

        resultVector.push_back(nums.front());
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] != resultVector.back())
                resultVector.push_back(nums[i]);
        nums.assign(resultVector.begin(), resultVector.end());
        return resultVector.size();
    }
};
