#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> findMissingElements(std::vector<int> &nums)
    {
        auto min = std::min_element(nums.begin(), nums.end());
        auto max = std::max_element(nums.begin(), nums.end());

        const int range = *max - *min + 1;
        bool uniq[range];
        std::fill(uniq, uniq + range, 0);

        for (auto &&i : nums)
            uniq[i - *min] = true;

        std::vector<int> res;

        for (int i = 0; i < range; i++)
            if (!uniq[i])
                res.push_back(i + *min);

        return res;
    }
};