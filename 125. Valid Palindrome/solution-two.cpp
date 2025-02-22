#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
    static bool isPalindrome(const std::string &str)
    {
        std::string lower_case_string;
        for (int i = 0; i < str.size(); i++)
            if (str[i] >= 'A' and str[i] <= 'Z')
                lower_case_string += str[i] + ('a' - 'A');
            else if (str[i] >= 'a' and str[i] <= 'z')
                lower_case_string += str[i];
            else if (str[i] >= '0' and str[i] <= '9')
                lower_case_string += str[i];

        std::string::iterator left = lower_case_string.begin();
        std::string::iterator right = lower_case_string.end() - 1;

        while (left < right)
        {
            if (*left != *right)
                return false;
            left++, right--;
        }

        return true;
    }
};
