#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
    int maxActiveSectionsAfterTrade(std::string &s)
    {
        s = '1' + s + '1';
        const int length = s.length();
        std::vector<std::pair<char, int>> clusters;

        int count, max_active_section{-2};
        char digit{};
        for (int i = 0; i < length;)
        {
            digit = s[i];
            count = 0;
            while (s[i] == digit)
            {
                count++;
                i++;
                max_active_section += (digit == '1' ? 1 : 0);
            }
            clusters.push_back(std::pair(digit, count));
        }

        if (clusters.size() < 5)
            return max_active_section;

        int ans{max_active_section};
        int start = 0, end = 4;
        while (end < clusters.size())
        {
            ans = std::max(ans, max_active_section + clusters[start + 1].second + clusters[end - 1].second);
            start += 2, end += 2;
        }
        return ans;
    }
};