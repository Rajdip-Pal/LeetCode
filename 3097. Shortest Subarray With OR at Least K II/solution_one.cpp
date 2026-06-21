#include <algorithm>
#include <vector>

class Solution
{
    inline int total_OR_in_range(const std::vector<int>::const_iterator &left, const std::vector<int>::const_iterator &right)
    {
        int result = 0;
        std::vector<int>::const_iterator tracker = left;
        while (tracker <= right)
            (result |= *tracker), tracker++;
        return result;
    }

public:
    int minimumSubarrayLength(const std::vector<int> &nums, const int &k)
    {
        /**
         * @author -> Rajdip Pal;
         * @param nums -> Reference to the numbers array;
         * @param k -> target Or value for a subarray;
         * @return length of the longest possible sub Array;
         *
         * Normal Brute Force Solution;
         *
         * Let's try it out ...
         */

        int current_or = nums.front(), ans;
        std::vector<int>::const_iterator left = nums.cbegin(), right = nums.cbegin();
        std::vector<int> OR_Result;

        while (right < nums.cend())
        {
            current_or = total_OR_in_range(left, right);
            if (current_or >= k)
            {
                if (left <= right)
                    OR_Result.push_back(right - left + 1), left++;
                else
                    left = ++right;
            }
            else
                right++;
        }

        return OR_Result.empty() ? -1 : *std::min_element(OR_Result.begin(), OR_Result.end());
    }
};

/*

a bitwiseOR b = c

*/

int main(int argc, char const *argv[])
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};
    nums.cend() + 1;
    return 0;
}
