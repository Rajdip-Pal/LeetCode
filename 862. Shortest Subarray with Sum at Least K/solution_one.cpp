#include <algorithm>
#include <ios>
#include <iostream>
#include <set>
#include <vector>

class Solution
{

public:
    int shortestSubarray(const std::vector<int> &nums, const int &k)
    {
        int minLength = INT32_MAX;
        long long sum{};
        std::multiset<std::pair<long long, int>> prefixSum;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if (sum >= k)
                minLength = std::min(minLength, i + 1);

            while (!prefixSum.empty() and (sum - prefixSum.begin()->first >= k))
                minLength = std::min(minLength, (i - prefixSum.begin()->second)),
                prefixSum.erase(prefixSum.begin());

            prefixSum.insert({sum, i});
        }
        return minLength > nums.size() ? -1 : minLength;
    }
};

auto init = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

void __test(std::vector<int> nums, int k)
{
    Solution solution;
    std::cout << std::endl
              << solution.shortestSubarray(nums, k) << "\n";
}

int main()
{
    __test({3, -2, 5}, 4);
}
