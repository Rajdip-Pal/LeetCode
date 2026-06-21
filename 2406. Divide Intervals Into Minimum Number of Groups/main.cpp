#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Greedy Solution 
 * Timr limit Exceeds the maximum limit.
 */

class Solution {
public:
    int minGroups(std::vector<std::vector<int>>& intervals) {
        int length = intervals.size();
        bool flag = false;
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<std::vector<int>>> groups;

        groups.push_back({{intervals[0]}});
        for (int i = 1; i < length; i++) {
            for (int j = 0; j < groups.size(); j++) {
                if (intervals[i][0] > groups[j].back()[1]) {
                    flag = true;
                    groups[j].push_back({intervals[i]});
                    break;
                }
            }
            if (flag)
                flag = false;
            else
                groups.push_back({{intervals[i]}});            
        }   

        for (auto &&i : groups) {
            for (auto &&j : i) {
                std::cout << "[" << j[0] << ", " << j[1] << "] ";  // For Debugging
            }
            std::cout << std::endl;
        }
        

        return groups.size();     
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
