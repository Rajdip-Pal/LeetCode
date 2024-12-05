#include <iostream>
#include <string>

class Solution
{
    /**
     * String Erase is a very bad option for this question;
     */
public:
    std::string makeFancyString(std::string &str)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        if (str.length() < 3)
            return str;

        for (int i = 2; i < str.size(); i++)
            if (str[i] == str[i - 1] and str[i] == str[i - 2])
                str.erase(i--, 1);

        return str;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
