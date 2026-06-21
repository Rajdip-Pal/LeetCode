#include <iostream>
#include <vector>

class Solution
{
public:
    static std::vector<int> getMaximumXor(const std::vector<int> &nums, const int &maximumBit)
    {
        int maximum_possible_xor = (1 << maximumBit) - 1, current_xor = 0;
        std::vector<int> answer(nums.size());

        for (int i = 0; i < answer.size(); i++)
            answer[answer.size() - i - 1] =
                (current_xor ^= nums[i]) ^ maximum_possible_xor;

        return answer;
    }
};

int init = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

int main(int argc, char const *argv[])
{
    std::vector<int> nums = {0, 1, 1, 3};
    std::vector<int> result = Solution::getMaximumXor(nums, 3);

    // Print the result
    std::cout << "Result: ";
    for (const auto &num : result)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
