#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
    static bool isPalindrome(const std::string &str)
    {
        std::string lowerCaseString = "", reverse_string = "";
        for (int i = 0; i < str.size(); i++)
            if (str[i] >= 'A' and str[i] <= 'Z')
                lowerCaseString += str[i] + ('a' - 'A');
            else if (str[i] >= 'a' and str[i] <= 'z')
                lowerCaseString += str[i];
            else if (str[i] >= '0' and str[i] <= '9')
                lowerCaseString += str[i];

        reverse_string = lowerCaseString;
        std::reverse(reverse_string.begin(), reverse_string.end());
        return lowerCaseString == reverse_string;
    }
};

int main(int argc, char const *argv[])
{
    std::cout << Solution::isPalindrome("A man, a plan, a canal: Panama") << std::endl;
    return 0;
}
