#include <cmath>
#include <cstdint>

class Solution
{
public:
    int reverse(int x)
    {
        int reversed = 0;
        while (x != 0)
        {
            if (reversed > INT32_MAX / 10 or reversed < INT32_MIN / 10)
                return 0;
            reversed = reversed * 10 + x % 10, x /= 10;
        }
        return reversed;
    }
};
