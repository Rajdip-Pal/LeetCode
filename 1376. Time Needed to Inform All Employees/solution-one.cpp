#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Solution
{
    void calculate_tottal_time(const std::map<int, std::vector<int>> &mangerEmployeeMap, const std::vector<int> &informTime, const int &currentHeadId, const int &totalTime, int &maxTime)
    {
        if (mangerEmployeeMap.find(currentHeadId) == mangerEmployeeMap.end())
        {
            maxTime = std::max(maxTime, totalTime);
            return;
        }
        else
        {
            for (const auto &employee : mangerEmployeeMap.at(currentHeadId))
                calculate_tottal_time(mangerEmployeeMap, informTime, employee, totalTime + informTime[employee], maxTime);
        }
    }

public:
    int numOfMinutes(const int &n, const int &headID, const std::vector<int> &manager, const std::vector<int> &informTime)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int totalTime{}, maxTime{};
        std::map<int, std::vector<int>> mangerAndEmployee;

        for (int i = 0; i < n; ++i)
            if (manager[i] != -1)
                mangerAndEmployee[manager[i]].push_back(i);

        calculate_tottal_time(mangerAndEmployee, informTime, headID, informTime[headID], maxTime);

        return maxTime;
    }
};
