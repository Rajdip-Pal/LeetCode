#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> maximumBeauty(std::vector<std::vector<int>> &items, std::vector<int> &queries)
    {
        std::vector<int> result = std::vector<int>(queries.size());
        std::vector<int> maxBeauty = std::vector<int>(items.size());
        std::vector<std::vector<int>>::const_iterator item;

        std::sort(items.begin(), items.end(),
                  [](const std::vector<int> &a, const std::vector<int> &b)
                  {
                      return (a.front() == b.front()) ? (a.back() < b.back()) : (a.front() < b.front());
                  });

        maxBeauty.at(0) = items.at(0).back();
        for (int i = 1; i < items.size(); i++)
            maxBeauty.at(i) = std::max(maxBeauty.at(i - 1), items.at(i).back());

        for (int i = 0; i < queries.size(); i++)
            if ((item = std::upper_bound(items.begin(), items.end(), queries.at(i),
                                         [](const int &a, const std::vector<int> &b)
                                         {
                                             return a < b.front();
                                         })) == items.begin())
                result.at(i) = 0;
            else
                result.at(i) = maxBeauty.at(item - items.begin() - 1);

        return result;
    }
};

auto init = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
