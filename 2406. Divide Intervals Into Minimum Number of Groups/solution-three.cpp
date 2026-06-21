#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Accepted Solution
 */

class Solution {
public:
    int minGroups(const std::vector<std::vector<int>>& intervals) {
        int i {}, j {};
        int max_overlapping {};
        int total_intervals = intervals.size();
        std::vector<int> starting_points, ending_points;

        for (i = 0; i < total_intervals; ++i) 
            starting_points.push_back(intervals[i][0]),
            ending_points.push_back(intervals[i][1]);

        std::sort(starting_points.begin(), starting_points.end());
        std::sort(ending_points.begin(), ending_points.end());

        i = 0;
        while (i < total_intervals && j <total_intervals) {
            if (starting_points[i] <= ending_points[j]) i++;
            else    j++;
            // no need of current overlapping because i-j defines current overlapping
            max_overlapping = std::max(max_overlapping, i-j);
        }

        return max_overlapping;     
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
