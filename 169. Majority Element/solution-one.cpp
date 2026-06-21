#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        if (nums.size() < 3)
            return nums.front();

        std::vector<std::pair<int, int>> elementFrequency;
        std::sort(nums.begin(), nums.end());

        elementFrequency.push_back(std::make_pair(nums.front(), 1));
        for (int i = 1; i < nums.size(); i++)
            if (elementFrequency.back().first == nums[i])
                elementFrequency.back().second++;
            else
                elementFrequency.push_back(std::make_pair(nums[i], 1));

        for (int i = 0; i < elementFrequency.size(); i++)
            if (elementFrequency[i].second > nums.size() / 2)
                return elementFrequency[i].first;

        return 0;
    }
};
