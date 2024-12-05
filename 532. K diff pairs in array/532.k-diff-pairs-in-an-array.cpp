#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */

// @lc code=start
class Solution
{
public:
    static int findPairs(std::vector<int> &nums, const int &k)
    {
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);

        int total_pairs{}, evaluated_value{};
        std::sort(nums.begin(), nums.end());

        unsigned indexI{}, indexJ{};
        while (indexI < nums.size() && indexJ < nums.size())
        {
            if (indexI >= indexJ)
            {
                indexJ++;
                continue;
            }
            evaluated_value = nums[indexJ] - nums[indexI];
            if (evaluated_value < k)
                indexJ++;
            else if (evaluated_value > k)
                indexI++;
            else
            {
                total_pairs++;
                indexI++;
                indexJ++;
                while (nums[indexI - 1] == nums[indexI] && indexI < nums.size() - 1)
                    indexI++;
            }
        }
        return total_pairs;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    std::vector<int> vec = {1, 1};
    int num = 0;
    std::cout << Solution::findPairs(vec, num);
    return 0;
}
