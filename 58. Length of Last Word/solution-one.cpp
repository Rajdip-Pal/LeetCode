#include <iostream>
#include <string>

class Solution
{
public:
    int lengthOfLastWord(const std::string &str)
    {
        int length{}, i = str.size() - 1;
        while (i >= 0)
        {
            if (str[i] == ' ')
                if (length > 0)
                    break;
                else
                    i--;
            else
                length++, i--;
        }
        return length;
    }
};
