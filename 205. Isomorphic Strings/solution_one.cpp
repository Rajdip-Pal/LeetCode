#include <cstring>
#include <string>

class Solution
{
    static int indexS[128], indexT[128];

public:
    bool isIsomorphic(const std::string &s, const std::string &t)
    {
        if (s.length() != t.length())
            return false;

        int i = 0;
        memset(indexS, 0, sizeof(indexS));
        memset(indexT, 0, sizeof(indexT));

        for (; i < s.length(); i++)
        {
            if (indexS[s[i]] != indexT[t[i]])
                return false;
            indexS[s[i]] = indexT[t[i]] = i + 1;
        }

        if (indexS[s[i]] != indexT[t[i]])
            return false;

        return true;
    }
};

int Solution::indexS[128],
    Solution::indexT[128];

int main()
{
    Solution s;
    std::string str1 = "egg";
    std::string str2 = "add";
    s.isIsomorphic(str1, str2);
    return 0;
}
