#include <vector>

class Solution
{
public:
    int uniqueXorTriplets(std::vector<int> &nums)
    {
        const int n = nums.size();
        return n < 3 ? n : 1 << std::__bit_width(n);
    }
};