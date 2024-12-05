#include <iostream>
#include <string>

class Solution
{
public:
    std::string makeFancyString(const std::string &str)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        if (str.length() < 3)
            return str;

        std::string result(str.size(), 0);
        result[0] = str[0],
        result[1] = str[1];

        int j{2};
        for (int i = 2; i < str.size(); i++)
            if ((str[i] != str[i - 2]) or (str[i] != str[i - 1]))
                result[j++] = str[i];

        result.resize(j);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
