#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

class Solution
{
    static std::vector<int> sequenceGenerate(const std::vector<int> &nums)
    {
        std::vector<int> __sequence(nums.size(), 1);

        int index{1};
        while (index < nums.size())
        {
            for (int j = 0; j < index; j++)
                if (nums[j] < nums[index])
                    __sequence[index] = std::max(__sequence[index], __sequence[j] + 1);
            index++;
        }

        return __sequence;
    }

public:
    static int minimumMountainRemovals(std::vector<int> &nums)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int maximumSequenceLength{};

        std::vector<int> LIS_List = sequenceGenerate(nums);
        std::reverse(nums.begin(), nums.end());
        std::vector<int> LDS_List = sequenceGenerate(nums);
        std::reverse(LDS_List.begin(), LDS_List.end());

        for (int i = 0; i < nums.size(); i++)
            if (LIS_List[i] != 1 and LDS_List[i] != 1)
                maximumSequenceLength = std::max(maximumSequenceLength, (LIS_List[i] + LDS_List[i] - 1));

        return nums.size() -
               maximumSequenceLength;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> nums = {2, 1, 1, 5, 6, 2, 3, 1};
    std::cout << Solution::minimumMountainRemovals(nums);
    return 0;
}
