#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution
{
public:
    static bool transportPossible(const int &capacity, const int &days, const std::vector<int> &weightsList)
    {
        int neededDays{}, weight{};
        for (int i{}; i < weightsList.size(); i++)
        {
            if (weight + weightsList[i] > capacity)
                neededDays++, weight = 0;
            weight += weightsList[i];
        }
        return ++neededDays <= days;
    }

    static int shipWithinDays(const std::vector<int> &weights, const int &days)
    {
        std::ios::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        std::size_t minimumCapacity{static_cast<std::size_t>(*std::max_element(weights.begin(), weights.end()))},
            maximumCapacity{static_cast<std::size_t>(std::accumulate(weights.begin(), weights.end(), 0))};

        if (days <= 1)
            return maximumCapacity;
        if (days >= weights.size())
            return minimumCapacity;

        std::size_t midCapacity{};
        while (minimumCapacity <= maximumCapacity)
        {
            midCapacity = minimumCapacity + (maximumCapacity - minimumCapacity) / 2;
            if (transportPossible(midCapacity, days, weights))
                maximumCapacity = midCapacity - 1;
            else
                minimumCapacity = midCapacity + 1;
        }

        return minimumCapacity;
    }
};
/*

weights = [1,2,3,4,5,6,7,8,9,10], days = 5

min = 10, max = 55
mid = 32 max = 31 min = 10
mid = 20 max = 19 min = 10
mid = 14 max = 19 min = 15
mid = 17 max = 16 min = 15
mid = 15 max = 14 min = 15
*/

int main(int argc, char const *argv[])
{
    std::vector<int> vec = {3, 2, 2, 4, 1, 4};
    int days = 29;

    std::cout << Solution::shipWithinDays(vec, 3) << std::endl;

    return 0;
}
