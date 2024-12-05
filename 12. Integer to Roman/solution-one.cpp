#include <iostream>
#include <string>
#include <array>

class Solution
{
public:
    std::string intToRoman(int num)
    {
        std::array<int, 13> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        std::array<std::string, 13> syb = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        std::string roman = "";
        int i = 0;
        while (num > 0)
        {
            while (num >= val[i])
            {
                roman += syb[i];
                num -= val[i];
            }
            i++;
        }
        return roman;
    }
};
