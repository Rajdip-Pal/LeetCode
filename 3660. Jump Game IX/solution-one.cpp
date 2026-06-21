#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
    std::vector<int> maxValue(const std::vector<int> &nums)
    {
        const int n = nums.size();

        std::vector<bool> visited(n, false);
        std::vector<std::pair<int, int>> val_idx(n);

        for (auto i = 0; i < n; i++)
            val_idx[i] = {nums[i], i};

        std::sort(val_idx.begin(), val_idx.end());

        

        std::vector<int>
            ans(nums.cbegin(), nums.cend());

        return ans;
    }
};