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
        vector<int> suffix_max(events.size());
        sort(events.begin(), events.end());

        suffix_max[events.size() - 1] = events[events.size() - 1][2];
        for (int i = events.size() - 2; i >= 0; i--)
            suffix_max[i] = std::max(events[i][2], suffix_max[i + 1]);

        int start, end, mid, nextEventIndex;
        for (int i = 0; i < events.size(); i++)
        {
            start = i + 1, end = events.size() - 1;
            nextEventIndex = -1;
            while (start <= end)
            {
                mid = start + (end - start) / 2;
                if (events[mid][0] > events[i][1])
                {
                    nextEventIndex = mid;
                    end = mid - 1;
                }
                else
                    start = mid + 1;

                if (nextEventIndex != -1)
                    total_sum = std::max(total_sum, events[i][2] + suffix_max[nextEventIndex]);
            }

            total_sum = std::max(total_sum, events[i][2]);
        }

        return total_sum;
    }
};
