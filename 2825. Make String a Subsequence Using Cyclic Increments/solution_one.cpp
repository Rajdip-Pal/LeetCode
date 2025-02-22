#include <string>

class Solution
{
public:
    bool canMakeSubsequence(const std::string &str1, const std::string &str2)
    {
        std::string::const_iterator it1 = str1.cbegin();
        std::string::const_iterator it2 = str2.cbegin();

        auto increment = [](const char &ch) -> char
        {
            return ch == 'z' ? 'a' : ch + 1;
        };

        while (it1 != str1.end() and it2 != str2.end())
            if ((*it1 == *it2) or (*it2 == increment(*it1)))
                ++it1, ++it2;
            else
                ++it1;

        return it2 == str2.end() ? true : false;
    }
};
