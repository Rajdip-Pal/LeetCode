class Solution
{
public:
    int maxProduct(int n)
    {
        int freq[10] = {};

        while (n > 0)
            freq[n % 10]++, n /= 10;

        int ans{1}, digit_to_collect{2};
        for (int digit = 9; digit >= 0; digit--)
            while (freq[digit] && digit_to_collect)
                digit_to_collect--, freq[digit]--, ans *= digit;

        return ans;
    }
};