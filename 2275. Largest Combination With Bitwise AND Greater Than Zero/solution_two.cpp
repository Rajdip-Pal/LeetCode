#include <vector>
#include <iostream>
#include <algorithm>

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC optimize("-ffloat-store")

auto init = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
}();

class Solution
{
public:
    int largestCombination(const std::vector<int> &candidates)
    {
        int result{}, count_in_each_position{};
        for (int i = 0; i < 24; i++)
        {
            count_in_each_position = 0;
            for (int j = 0; j < candidates.size(); j++)
                if ((1 << i) & candidates[j])
                    count_in_each_position++;
            result = std::max(result, count_in_each_position);
        }

        return result;
    }
};
