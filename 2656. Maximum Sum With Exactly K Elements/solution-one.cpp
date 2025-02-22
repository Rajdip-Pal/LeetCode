#include <iostream>
#include <vector>
#include <algorithm>

/*
 * Solution 2656. Maximum Sum With Exactly K Elements
 *
 * @Start
 */

class Solution
{
public:
    int maximizeSum(const std::vector<int> &nums, const int &k)
    {
        int result{};
        int maxElement = *std::max_element(nums.begin(), nums.end());
        for (int i = 0; i < k; i++)
            result += maxElement + i;
        return result;
    }
};

/**
 * @End
 */

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
