#include <string>
#include <vector>

class Solution
{
public:
    int maximumLength(const std::string &s)
    {
        int n = s.size();
        int l = 1, r = n, mid;

        auto helper = [&](const int &x) -> bool
        {
            std::vector<int> cnt(26, 0);
            int p = 0;

            for (int i = 0; i < n; i++)
            {
                while (s[p] != s[i])
                    p++;
                if (i - p + 1 >= x)
                    cnt[s[i] - 'a']++;
                if (cnt[s[i] - 'a'] > 2)
                    return true;
            }

            return false;
        };

        if (!helper(l))
            return -1;

        while (l + 1 < r)
            (helper(mid = (l + r) / 2)) ? l = mid : r = mid;

        return l;
    }
};
