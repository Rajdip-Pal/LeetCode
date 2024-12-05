#include <string>

class Solution
{
public:
    int findNthDigit(int n)
    {
        if (n < 10)
            return n;
        int len = 1;
        long long start = 1;
        long long count = 9;
        while (n > len * count)
        {
            n -= len * count;
            len += 1;
            start *= 10;
            count *= 10;
        }
        start += (n - 1) / len;
        return std::to_string(start)[(n - 1) % len] - '0';
    }
};
