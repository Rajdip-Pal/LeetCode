#include <iostream>
#include <vector>

class Solution
{
public:
    static int find_power(const std::vector<int>::const_iterator &start, const std::vector<int>::const_iterator &end)
    {
        std::vector<int>::const_iterator it = start + 1;
        while (it <= end and *it == *(it - 1) + 1)
            ++it;
        return it <= end ? -1 : *end;
    }

public:
    std::vector<int> resultsArray(const std::vector<int> &nums, const int &k)
    {
        std::vector<int> results;
        results.reserve(nums.size() - k + 1);

        std::vector<int>::const_iterator start = nums.cbegin(), end = nums.cbegin() + k - 1;
        while (end < nums.cend())
            results.push_back(find_power(start++, end++));

        return results;
    }
};

auto init = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

void __test(std::vector<int> nums, int k)
{
    Solution solution;
    std::vector<int> results = solution.resultsArray(nums, k);
    for (auto i : results)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main()
{
    __test({1, 2, 3, 4, 5}, 3);
    __test({1, 2, 3, 4, 5}, 4);
    __test({1, 2, 3, 4, 5}, 5);

    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> nums2 = {1, 5, 9, 7, 6, 3};
    std::cout << Solution::find_power(nums.cbegin(), nums.cbegin()) << std::endl;
    std::cout << Solution::find_power(nums2.cbegin(), nums2.cbegin() + 2) << std::endl;
    std::cout << Solution::find_power(nums2.cbegin(), nums2.cend()) << std::endl;
    return 0;
}
