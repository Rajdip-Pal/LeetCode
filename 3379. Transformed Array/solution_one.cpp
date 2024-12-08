#include <iostream>
#include <ostream>
#include <vector>

using ::std::cout;
using ::std::vector;

std::ostream &operator<<(std::ostream &os, const std::vector<int> &arr)
{
    os << "[";
    for (size_t i = 0; i < arr.size() - 1; ++i)
        os << arr[i] << ", ";
    os << arr[arr.size() - 1] << "]";
    return os;
}

class Solution
{
public:
    vector<int> constructTransformedArray(const vector<int> &nums)
    {
        const vector<int> reverse_nums(nums.rbegin(), nums.rend());
        vector<int> result(nums.size());

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] >= 0)
                result[i] = nums[(i + nums[i]) % nums.size()];
            else
                result[i] = reverse_nums[((nums.size() - 1 - i) + -nums[i]) % nums.size()];

        return result;
    }
};
