#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{

    bool possible_stores(const int &val, const int &stores, const std::vector<int> &quantities)
    {
        int count{};
        for (int i = 0; i < quantities.size(); i++)
            count += (quantities.at(i) % val == 0) ? quantities.at(i) / val : quantities.at(i) / val + 1;
        return count > stores;
    }

public:
    int minimizedMaximum(const int &n, const std::vector<int> &quantities)
    {
        int ans;
        int left = 1, right = *std::max_element(quantities.begin(), quantities.end()), mid;

        while (left <= right)
            possible_stores((mid = left + (right - left) / 2), n, quantities) ? (left = mid + 1) : (ans = mid, right = mid - 1);

        return ans;
    }
};

auto init = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
