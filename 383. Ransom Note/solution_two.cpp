#include <iostream>
#include <string>

class Solution
{
public:
    bool canConstruct(std::string ransomNote, std::string magazine)
    {
        int count[128] = {0};

        for (char c : magazine)
            count[c]++;

        for (char c : ransomNote)
            if (count[c]-- == 0)
                return false;

        return true;
    }
};

auto init = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
