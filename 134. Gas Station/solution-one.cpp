#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>

class Solution
{
public:
    int canCompleteCircuit(const std::vector<int> &gas, const std::vector<int> &cost)
    {
        std::ios::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        int fuel{}, total_fuel_at_end{}, start{};
        for (int i = 0; i < gas.size(); i++)
        {
            total_fuel_at_end += gas[i] - cost[i];
            fuel += gas[i] - cost[i];
            if (fuel < 0)
                fuel = 0,
                start = i + 1;
        }

        return total_fuel_at_end < 0 ? -1 : start;
    }
};

/*

[1,2,3,4,5]
[3,4,5,1,2]

-2 -2 -2 3 3


[5,8,2,8]
[6,5,6,6]

-1 3 -4 3

*/
