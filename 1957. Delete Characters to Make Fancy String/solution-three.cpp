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

        std::string result;
        result.reserve(str.size());
        result.push_back(str[0]);
        result.push_back(str[1]);

        for (int i = 2; i < str.size(); i++)
            if ((result[result.size() - 1] == result[result.size() - 2]) and str[i] == result.back())
                ;
            else
                result.push_back(str[i]);

        result.shrink_to_fit();
        return result;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
