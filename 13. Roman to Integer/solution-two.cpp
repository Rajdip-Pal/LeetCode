#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
    int charValue(const char &c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    };

public:
    int romanToInt(std::string &str)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int totalValue{};
        char maxChar = 'I';

        while (!str.empty())
            if (charValue(str.back()) >= charValue(maxChar))
                totalValue += charValue(maxChar = str.back()), str.pop_back();
            else
                totalValue -= charValue(str.back()), str.pop_back();

        return totalValue;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
