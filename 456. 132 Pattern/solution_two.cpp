#include <vector>

class Solution
{
public:
    bool find132pattern(const std::vector<int> &nums)
    {
        /**
         * @author :  Rajdip Pal
         * @param nums: a list of numbers (not sorted or maybe sorted)
         * @return: a bool value if 132 pattern is found or not
         */

        int current_minimum = nums.at(0);
        // {first, second} first -> 132 pattern's second element, second -> 132 pattern's first element
        std::vector<std::pair<int, int>> decreasing_stack;

        for (int i = 0; i < nums.size(); i++)
        {
            while (!decreasing_stack.empty() and nums.at(i) >= decreasing_stack.back().first)
                decreasing_stack.pop_back();
            if (!decreasing_stack.empty() and nums.at(i) > decreasing_stack.back().second)
                return true;
            decreasing_stack.push_back({nums.at(i), current_minimum});
            current_minimum = std::min(current_minimum, nums.at(i));
        }
        return false;
    }
};
