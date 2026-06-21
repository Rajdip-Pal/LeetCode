class Solution
{
public:
    int arrangeCoins(const int &n)
    {
        if (n < 3)
            return 1;
        if (n < 6)
            return 2;

        long long int left = 1, right = n / 2, mid;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (mid * (mid + 1) / 2 > n)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left - 1;
    }
};
