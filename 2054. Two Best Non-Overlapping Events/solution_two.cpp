#include <algorithm>
#include <vector>

using ::std::sort;
using ::std::vector;

class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        int total_sum{};

        sort(events.begin(),
             events.end(),
             [](const vector<int> &a, const vector<int> &b) -> bool
             {
                 if (a.front() != b.front())
                     return a.front() < b.front();
                 return a.back() > b.back();
             });

        vector<int> suffix_max(events.size());
        suffix_max[events.size() - 1] = events[events.size() - 1][2];
        for (int i = events.size() - 2; i >= 0; i--)
            suffix_max[i] = std::max(events[i][2], suffix_max[i + 1]);

        for (int i = 0; i < events.size(); i++)
        {
            total_sum = std::max(total_sum, events.at(i).back());
            int it =
                std::lower_bound(events.cbegin() + i + 1,
                                 events.cend(),
                                 std::vector<int>{events.at(i).at(1) + 1, -1, -1}) -
                events.cbegin();
            if (it < events.size())
                total_sum = std::max(total_sum, events[i][2] + suffix_max[it]);
        }

        return total_sum;
    }
};
