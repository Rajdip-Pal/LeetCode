
/**
 * @file minimumSubarrayLength.cpp
 * @brief Find the length of the shortest subarray whose sum is greater than or equal to k
 * @author Rajdip Pal
 */

#include <array>
#include <bitset>
#include <iostream>
#include <vector>

class Solution
{
    std::string performe_or(const std::string &op1, const std::string &op2, std::array<int, 32> &set_unset_record)
    {
        std::string result = op2;

        for (int i = 0; i < result.length(); i++)
            if (result[i] == '1')
                set_unset_record[i]++;

        for (int i = 0; i < op1.length(); i++)
            if (op1[i] == '1' || op2[i] == '1')
                result[i] = '1';

        return result;
    }

    std::string performe_reverse_or(const std::string &op1, const std::string &op2, std::array<int, 32> &set_unset_record)
    {
        std::string result = op1;
        for (int i = 0; i < op2.length(); i++)
            if (op2[i] == '1')
                if ((--set_unset_record[i]) == 0)
                    result[i] = '0';

        return result;
    }

public:
    /**
     * @brief Find the length of the shortest subarray whose sum is greater than or equal to k
     * @param nums Reference to the numbers array
     * @param k Target value for a subarray
     * @return Length of the shortest subarray whose sum is greater than or equal to k, or -1 if no such subarray exists
     */
    int minimumSubarrayLength(const std::vector<int> &nums, const int &k)
    {
        int shortestLength = INT32_MAX;
        std::string bitwise_or = std::bitset<32>(0).to_string();
        std::array<int, 32> set_unset_record;

        int left = 0, right = 0;
        while (right < nums.size())
        {
            bitwise_or = performe_or(bitwise_or, std::bitset<32>(nums[right]).to_string(), set_unset_record);

            while (left <= right and std::bitset<32>(bitwise_or).to_ulong() >= k)
            {
                shortestLength = std::min(shortestLength, right - left + 1);
                bitwise_or = performe_reverse_or(bitwise_or, std::bitset<32>(nums[left]).to_string(), set_unset_record);
                left++;
            }

            right++;
        }

        return shortestLength == INT32_MAX ? -1 : shortestLength;
    }
};

auto init = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int main(int argc, char const *argv[])
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};
    nums.cend() + 1;

    // Solution::minimumSubarrayLength(nums, 11);
    return 0;
}
