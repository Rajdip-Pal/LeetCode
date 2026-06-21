#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Solution
{
    int find_times_in_paths(const int &currentEmployee, const int &currentHead,
                            const std::vector<int> &manager,
                            const std::vector<int> &informTime,
                            std::vector<int> &timeToGetMessageToTheEmployee)
    {
        if (timeToGetMessageToTheEmployee[currentHead] != -1)
            return timeToGetMessageToTheEmployee[currentEmployee] =
                       timeToGetMessageToTheEmployee[currentHead] +
                       informTime[currentHead];
        return timeToGetMessageToTheEmployee[currentEmployee] =
                   informTime[currentHead] +
                   find_times_in_paths(currentHead, manager[currentHead],
                                       manager, informTime,
                                       timeToGetMessageToTheEmployee);
    }

public:
    int numOfMinutes(const int &n, const int &headID,
                     const std::vector<int> &manager,
                     const std::vector<int> &informTime)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int maximumTime{};
        std::vector<int> timetoGetNewsFromHeadMangaer(n, -1);

        timetoGetNewsFromHeadMangaer[headID] = 0;

        for (int i = 0; i < n; i++)
            if (timetoGetNewsFromHeadMangaer[i] == -1)
                if (manager[i] != -1)
                    maximumTime = std::max(
                        maximumTime,
                        find_times_in_paths(i, manager[i], manager, informTime,
                                            timetoGetNewsFromHeadMangaer));

        return maximumTime;
    }
};
