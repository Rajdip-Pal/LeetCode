#include <cstddef>
#include <vector>

class Solution
{
    static bool elements[static_cast<std::size_t>(1e6 + 1)];

public:
    static long long maximumSubarraySum(const std::vector<int> &nums, const int &k)
    {
        std::size_t subarraySum{}, maxSubarraySum{};
        std::vector<int>::const_iterator i = nums.cbegin(), start = nums.cbegin();

        for (; i < nums.cend(); i++)
        {
            if (elements[*i])
            {
                subarraySum = 0;
                while (start < i)
                    elements[*start] = false, start++;
            }

            elements[*i] = true, subarraySum += *i;

            if (i - start == k - 1)
                maxSubarraySum = std::max(maxSubarraySum, subarraySum),
                elements[*start] = false,
                subarraySum -= *start,
                start++;
        }

        if (i - start == k - 1)
            maxSubarraySum = std::max(maxSubarraySum, subarraySum),
            elements[*start] = false,
            subarraySum -= *start,
            start++;

        return maxSubarraySum;
    }
};

bool Solution::elements[static_cast<std::size_t>(1e6 + 1)];
