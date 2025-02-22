#include <iostream>
#include <vector>
#include <algorithm>

/**
 * greedy solution 
 * time limit exceed.
 */

class Solution {
public:
    int minGroups(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        int total_intervals = intervals.size();

        std::vector<int> groups_back_index;
        groups_back_index.push_back(0);
        int total_groups = groups_back_index.size();
        bool flag = false;

        for (int i = 1; i < total_intervals; i++) {
            for(int j = 0; j < total_groups; j++) {
                if (intervals[i][0] > intervals[groups_back_index[j]][1]) {
                    groups_back_index[j] = i, flag = true;
                    break;
                }
            }
            if (flag)   flag = false;
            else {
                groups_back_index.push_back(i);
                total_groups++;
            }
        }
        
        return total_groups;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
