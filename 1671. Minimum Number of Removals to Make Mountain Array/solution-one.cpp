#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

class Solution
{
    static void find_subsequence_length(int &result, const std::vector<int> &nums)
    {
        std::vector<int> __sequenceIncreasing(nums.size(), 1);
        std::vector<int> __sequenceDecreasing(nums.size(), 1);
        std::less<int> isLesser;

        int index{1}, j{};

        while (index < nums.size())
        {
            for (j = 0; j < index; j++)
                if (isLesser(nums[j], nums[index]))
                    __sequenceIncreasing[index] = std::max(__sequenceIncreasing[index], __sequenceIncreasing[j] + 1);
            index++;
        }

        index = nums.size() - 2;
        while (index >= 0)
        {
            for (j = nums.size() - 1; j > index; j--)
                if (isLesser(nums[j], nums[index]))
                    __sequenceDecreasing[index] = std::max(__sequenceDecreasing[index], __sequenceDecreasing[j] + 1);
            index--;
        }

        result = 0;
        for (index = 0; index < nums.size(); index++)
            if (__sequenceIncreasing[index] != 1 and __sequenceDecreasing[index] != 1)
                result = std::max(result, __sequenceIncreasing[index] + __sequenceDecreasing[index] - 1);
    }

public:
    static int minimumMountainRemovals(const std::vector<int> &nums)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int maximumSequenceLength{};
        find_subsequence_length(maximumSequenceLength, nums);
        return nums.size() - maximumSequenceLength;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> nums = {2, 1, 1, 5, 6, 2, 3, 1};
    std::cout << Solution::minimumMountainRemovals(nums);
    return 0;
}
