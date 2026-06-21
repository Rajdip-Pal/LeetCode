#include <algorithm>
#include <vector>

using ::std::vector;

/*
    BRUTE FORCE SOLUTION;
*/

class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        int total_sum{};

        std::sort(events.begin(), events.end(),
                  [](const vector<int> &a, const vector<int> &b) -> bool
                  {
                      if (a.front() != b.front())
                          return a.front() < b.front();
                      else
                          return a[1] < b[1];
                  });

        for (int i = 0; i < events.size(); i++)
        {
            total_sum = std::max(total_sum, events[i][2]);
            for (int j = i + 1; j < events.size(); j++)
                if (events[j][0] > events[i][1])
                    total_sum = std::max(total_sum, events[i][2] + events[j][2]);
        }

        return total_sum;
    }
};
