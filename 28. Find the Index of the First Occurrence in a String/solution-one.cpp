#include <string>

class Solution
{
public:
    int strStr(std::string &haystack, std::string &needle)
    {
        std::size_t pos = haystack.find(needle);
        if (pos != std::string::npos)
            return pos;
        return -1;
    }
};
