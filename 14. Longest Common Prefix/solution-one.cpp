#include <string>
#include <vector>

class Solution
{
public:
    std::string longestCommonPrefix(const std::vector<std::string> &strs)
    {
        if (strs.size() <= 1)
            return strs.front();

        if (strs.front().empty())
            return "";

        char commonCharacter{};
        std::string prefix = "";

        for (int i = 0; i < strs.front().size(); i++)
        {
            commonCharacter = strs.front()[i];
            for (int j = 1; j < strs.size(); j++)
                if (i >= strs[j].size() or strs[j][i] != commonCharacter)
                    return prefix;
            prefix.push_back(commonCharacter);
        }

        return prefix;
    }
};
