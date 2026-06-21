#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    void rotate(std::vector<int> &nums, int &k)
    {
        // bekar method
        k = k % nums.size();
        for (int i = 0; i < k; i++)
            nums.insert(nums.begin(), nums.back()), nums.pop_back();
    }
};
