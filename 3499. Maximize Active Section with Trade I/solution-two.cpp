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
        std::vector<int> cluster_lengths;

        int count, max_active_section{-2};
        char digit{};
        for (int i = 0; i < length;)
        {
            digit = s[i];
            count = 0;
            while (s[i++] == digit && ++count)
                ;
            cluster_lengths.push_back(count);
        }

        for (int i = 0; i < cluster_lengths.size(); i += 2)
            max_active_section += cluster_lengths[i];

        if (cluster_lengths.size() < 5)
            return max_active_section;

        int ans{max_active_section};
        for (int i = 3; i < cluster_lengths.size(); i += 2)
            ans = std::max(ans, max_active_section + cluster_lengths[i] + cluster_lengths[i - 2]);

        return ans;
    }
};