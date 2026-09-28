#include "string"

class Solution
{
public:
    int maxDepth(std::string &s)
    {
        int depth{}, maxDepth{};

        for (size_t i = 0; i < s.size(); i++)
        {
            const char ch = s[i];
            if (ch == '(' or ch == ')')
            {
                if (ch == '(')
                    depth++;
                if (ch == ')')
                    depth--;
                maxDepth = std::max(depth, maxDepth);
            }
        }

        return maxDepth;
    }
};