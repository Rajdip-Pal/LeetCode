#include <iostream>
#include <string>
#include <cmath>
#include <vector>

class Solution
{
public:
    static std::string convert(const std::string &str, const int &numRows)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        if (numRows == 1 or numRows >= str.length())
            return str;
        if (str.length() <= 2)
            return str;

        int start{};
        int group_length = 2 * numRows - 2;
        int half_group_length = group_length / 2;
        std::vector<std::string> groups((str.length() - 1) / group_length + 1);
        std::string result = "";

        for (int i = 0; i < groups.size(); i++)
        {
            groups[i] = str.substr(start, group_length);
            start += group_length;
        }

        for (int i = 0; i < groups.size(); i++)
            result += groups[i].front();

        for (int i = 1; i < half_group_length; i++)
            for (int j = 0; j < groups.size(); j++)
            {
                if ((i < groups[j].length()))
                    result += groups[j][i];
                if ((group_length - i < groups[j].length()))
                    result += groups[j][group_length - i];
            }

        for (int i = 0; i < groups.size(); i++)
            if (half_group_length < groups[i].size())
                result += groups[i][half_group_length];

        return result;
    }
};

int main(int argc, char const *argv[])
{
    std::cout << Solution::convert("PAYPALISHIRING", 3) << std::endl;
    return 0;
}
