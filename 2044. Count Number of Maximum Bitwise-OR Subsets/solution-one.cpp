#include <iostream>
#include <vector>

/**
 * Leetcode problem : 2044. Count Number of Maximum Bitwise-OR Subsets
 *
 * @Start
 */

class Solution {
    static void searchThroughAll(const std::vector<int>& elements, int index, int current_or, const int& max_or, int& result) {
        if (index == elements.size()){
            result += current_or == max_or ? 1 : 0;
        } else {
            searchThroughAll(elements, index+1,  current_or, max_or, result);
            searchThroughAll(elements,  index+1, current_or | elements[index], max_or, result);
        }
    }

public:
    static int countMaxOrSubsets(std::vector<int>& nums) {
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);

        int max_or_value = nums[0], number_of_subset {};
        for (int i = 1; i < nums.size(); i++)
            max_or_value = max_or_value | nums[i];
        searchThroughAll(nums, 0, 0,  max_or_value, number_of_subset);
        return number_of_subset;
    }
};

/**
 * @end
 */

/**
 * Solution Discussion and thoughts --
 *
 * Q. How can we actually increase bitwise OR value ?
 *    Bitwise OR value can not decrease in any case maybe it will be same or increase;
 *
 */

int main(int argc, char const *argv[])
{

    return 0;
}
