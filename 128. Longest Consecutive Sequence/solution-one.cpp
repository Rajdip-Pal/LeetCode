#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <chrono>

class Solution
{
public:
    static int longestConsecutive(std::vector<int> &nums)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        if (nums.size() < 2)
            return nums.size();

        std::sort(nums.begin(), nums.end());

        int currentConsecutive{1}, maxConsecutive{};
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == nums[i - 1] + 1)
                currentConsecutive++;
            else if (nums[i] != nums[i - 1])
                maxConsecutive = std::max(currentConsecutive, maxConsecutive),
                currentConsecutive = 1;

        maxConsecutive = std::max(currentConsecutive, maxConsecutive);
        return maxConsecutive;
    }
};

int main(int argc, char const *argv[])
{
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int>
        nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    Solution::longestConsecutive(nums);

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Duration : " << std::chrono::duration<double, std::milli>(end - start).count() << " ms." << std::endl;

    return 0;
}
