#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    static int findLengthOfShortestSubarray(const std::vector<int> &arr)
    {
        int minLength = arr.size() - 1;
        std::vector<int>::const_iterator start = arr.cbegin(), end = arr.cend() - 1;

        while (start != end and *start <= *(start + 1))
            ++start;

        if (start == arr.cend() - 1)
            return 0;

        minLength = std::min(minLength, static_cast<int>(arr.cend() - start - 1));

        while (end > arr.cbegin() and *end >= *(end - 1))
            --end;

        minLength = std::min(minLength, static_cast<int>(end - arr.cbegin()));

        std::vector<int>::const_iterator left = arr.cbegin(), right = arr.cend() - 1;
        while (left <= start)
        {
            while (right + 1 < arr.cend() and *left > *right)
                ++right;
            while (*right > *left and *right >= *(right - 1) and *(right - 1) >= *left)
                --right;
            if (*left <= *right)
                minLength = std::min(minLength, static_cast<int>(right - left - 1));
            ++left;
        }

        return minLength;
    }
};

auto init = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

void __print(const std::vector<int> &arr)
{
    for (const auto &i : arr)
        std::cout << i << " ";
    std::cout << std::endl;
}

void __test(const std::vector<int> &arr)
{
    __print(arr);
    std::cout << Solution::findLengthOfShortestSubarray(arr) << std::endl;
}

int main(int argc, char const *argv[])
{
    __test({1, 2, 3, 10, 4, 2, 3, 5});
    return 0;
}
