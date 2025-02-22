#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/**
 * Problem Statement = 2419. Longest Subarray With Maximum Bitwise AND
 *
 * Solution Start
 */

class Solution {
public:
    int longestSubarray(const std::vector<int>& nums) {
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);

        int maximum_length{}, current_length{};
        int max_element {*std::max_element(nums.begin(), nums.end())};

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == max_element) {
                current_length++;
                maximum_length = std::max(maximum_length, current_length);
            } else {
                current_length = 0;
            }

        }
        return maximum_length;
    }
};

/**
 * Solution End
 */

int main(int argc, char const *argv[])
{

    return 0;
}
