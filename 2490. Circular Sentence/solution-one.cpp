#include <iostream>
#include <string>

class Solution
{
public:
    bool isCircularSentence(const std::string &sentence)
    {
        if (sentence.front() == sentence.back())
        {
            for (int i = 1; i < sentence.length() - 1; i++)
                if (sentence[i] == ' ' and sentence[i - 1] != sentence[i + 1])
                    return false;
            return true;
        }
        return false;
    }
};
