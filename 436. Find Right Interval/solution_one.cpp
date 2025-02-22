#include <algorithm>
#include <vector>

class Solution
{
public:
    std::vector<int> findRightInterval(const std::vector<std::vector<int>> &intervals)
    {
        /**
         * @author :  Rajdip Pal
         * @param intervals: a list of intervals
         * @return: a list of rightInterval index
         */

        std::vector<int> result(intervals.size(), -1);
        std::vector<std::pair<int, int>> sorted_start_with_index;
        std::vector<std::pair<int, int>>::const_iterator iter;

        for (int i = 0; i < intervals.size(); i++)
            sorted_start_with_index.push_back(std::make_pair(intervals[i][0], i));

        std::sort(sorted_start_with_index.begin(), sorted_start_with_index.end(),
                  [](const std::pair<int, int> &a, const std::pair<int, int> &b)
                  { return a.first < b.first; });

        for (int i = 0; i < intervals.size(); i++)
            if ((iter = std::lower_bound(sorted_start_with_index.cbegin(),
                                         sorted_start_with_index.cend(),
                                         std::make_pair(intervals.at(i).back(), 0),
                                         [](const std::pair<int, int> &a, const std::pair<int, int> &b)
                                         { return a.first < b.first; })) != sorted_start_with_index.end())
                result[i] = iter->second;

        return result;
    }
};
