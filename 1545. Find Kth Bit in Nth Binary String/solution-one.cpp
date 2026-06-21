#include <iostream>
#include <string>
#include <algorithm>

/**
 * Solution = 1545. Find Kth Bit in Nth Binary String
 *
 * @start
 */

class Solution
{
    static std::string invertString(std::string str)
    {
        for (int i = 0; i < str.size(); i++)
            if (str[i] == '1')
                str[i] = '0';
            else if (str[i] == '0')
                str[i] = '1';

        return str;
    }
    static std::string generateString(const int n)
    {
        if (n == 1)
            return "0";
        else
        {
            std::string previousString = generateString(n - 1);
            std::string invert = invertString(previousString);
            std::reverse(invert.begin(), invert.end());
            return previousString + "1" + invert;
        }
    }

public:
    static char findKthBit(int n, int k)
    {
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);

        return generateString(n)[k-1];
    }
};

/**
 * @end
 */

int main(int argc, char const *argv[])
{
    std::cout << Solution::findKthBit(3, 1) << std::endl;
    return 0;
}
