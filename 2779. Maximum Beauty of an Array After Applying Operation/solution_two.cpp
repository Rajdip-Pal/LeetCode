#include <algorithm>
#include <vector>

class Solution
{
public:
    int maximumBeauty(std::vector<int> &nums, const int &k)
    {
        std::sort(nums.begin(), nums.end());

        std::vector<int> min_nums(nums.size()), max_nums(nums.size());
        std::transform(nums.cbegin(), nums.cend(), min_nums.begin(),
                       [k](const int &num) -> int
                       { return num - k; });
        std::transform(nums.cbegin(), nums.cend(), max_nums.begin(),
                       [k](const int &num) -> int
                       { return num + k; });

        int length{};
        int i{}, j{};

        while (i < min_nums.size() and j < max_nums.size())
            (min_nums[i] <= max_nums[j]) ? i++ : j++,
                length = std::max(length, i - j);

        return length;
    }
};
