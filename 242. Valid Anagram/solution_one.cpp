#include <array>
#include <string>

class Solution
{
public:
    bool isAnagram(const std::string &s, const std::string &t)
    {
        auto frequency = [](const std::string &s) -> std::array<unsigned, 26>
        {
            std::array<unsigned, 26> result;
            for (char c : s)
                result[c - 'a']++;
            return result;
        };

        return frequency(s) == frequency(t);
    }
};
