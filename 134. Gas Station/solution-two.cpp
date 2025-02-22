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

        int totalGas{}, totalCost{};

        for (int i = 0; i < gas.size(); i++)
            totalGas += gas[i], totalCost += cost[i];

        if (totalGas - totalCost >= 0)
        {
            int fuel{}, start{};
            for (int i = 0; i < gas.size(); i++)
                if ((fuel += gas[i] - cost[i]) < 0)
                    fuel = 0, start = i + 1;
            return start;
        }

        return -1;
    }
};
