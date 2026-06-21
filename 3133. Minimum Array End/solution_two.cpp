#include <bitset>

class Solution
{
public:
    long long minEnd(const int &n, const int &x)
    {
        std::string bits_x(std::bitset<64>(x).to_string()), bits_n(std::bitset<64>(n - 1).to_string());
        std::string::reverse_iterator it_x = bits_x.rbegin(), it_n = bits_n.rbegin();

        while (it_x != bits_x.rend() && it_n != bits_n.rend())
        {
            if (*it_x == '1')
                it_x++;
            else
            {
                if (*it_n == '1')
                    *it_x = '1';
                it_x++;
                it_n++;
            }
        }

        return std::bitset<64>(bits_x).to_ullong();
    }
};
