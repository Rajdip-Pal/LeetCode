#include <iostream>
#include <vector>
#include <queue>
#include <set>

class Solution {
public:
    std::vector<int> smallestRange(std::vector<std::vector<int>>& nums) {
        int number_of_lists = nums.size();

        std::vector<int> lengths(number_of_lists);
        for (int i = 0; i < number_of_lists; i++)
            lengths[i] = nums[i].size();

        std::vector<int> pointers(number_of_lists, 0);
        int index{};

        std::vector<int> minimum_range;
        int minimum_range_length = INT32_MAX, range_length;

        std::set<std::vector<int>> min_value;
        for (int i = 0; i < number_of_lists; i++)
            min_value.insert({nums[i][pointers[i]], i, pointers[i]});

        while (true) {
            min_value.insert(
                {nums[index][pointers[index]], index, pointers[index]});

            range_length = (*min_value.rbegin())[0] - (*min_value.begin())[0];
            if (range_length < minimum_range_length) {
                minimum_range_length = range_length;
                minimum_range = {(*min_value.begin())[0],
                                 (*min_value.rbegin())[0]};
            }

            index = (*min_value.begin())[1];
            pointers[index] += 1;
            min_value.erase(min_value.begin());

            if (pointers[index] >= lengths[index]) {
                return minimum_range;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    std::vector<std::vector<int>> nums = {{4, 10, 15}};
    auto result = solution.smallestRange(nums);
    std::cout << "[" << result[0] << ", " << result[1] << ", " << result[2] << "]";
    return 0;
}
