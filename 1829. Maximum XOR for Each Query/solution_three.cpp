#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    /**
     * @author Rajdip Pal;
     * @param nums consist reference to a sorted vector in non-decreasing order;
     * @param maximumBit consist a integer which represents the number of maximum bit in the number;
     * @return all the value of k < 2^maximumBit fro each query in a vector;
     */
    static std::vector<int> getMaximumXor(const std::vector<int> &nums, const int &maximumBit)
    {
        int maximum_possible_xor = (1 << maximumBit) - 1;
        int current_xor = 0;
        std::vector<int> answer(nums.size());

        for (int i = 0; i < answer.size(); i++)
            answer[answer.size() - i - 1] = ~(current_xor ^= nums[i]) & maximum_possible_xor;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> nums = {0, 1, 1, 3};
    Solution::getMaximumXor(nums, 3);
    return 0;
}
