#include <cstddef>
class Solution
{
public:
    int mySqrt(const int &x)
    {
        std::size_t left = 0, right = x, mid;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (mid * mid == x)
                return mid;
            else if (mid * mid > x)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return right;
    }
};
