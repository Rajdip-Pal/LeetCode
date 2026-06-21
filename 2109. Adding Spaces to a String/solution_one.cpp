#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    std::string addSpaces(const std::string &s, const std::vector<int> &spaces)
    {
        std::string result;
        result.reserve(s.length() + spaces.size());

        std::string::const_iterator it = s.cbegin();
        std::vector<int>::const_iterator position = spaces.cbegin();

        for (int i = 0; i < s.length(); ++i)
        {
            if (position != spaces.cend() && i == *position)
                result.push_back(' '), ++position;
            result += *it, ++it;
        }

        return result;
    }
};

auto init = []() -> std::nullptr_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
