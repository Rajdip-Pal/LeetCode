#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <algorithm>

class Solution
{
    static bool canObtain(std::vector<int> stations, const long long &midPower, const int &r, int k)
    {
        long long sum{};
        int totalCity = stations.size();
        for (int i = 0; i < r && i < totalCity; i++)
            sum += stations[i];
        for (int i = 0; i < totalCity; i++)
        {
            if (i - r - 1 >= 0)
                sum -= stations[i - r - 1];
            if (i + r < totalCity)
                sum += stations[i + r];
            if (sum < midPower)
            {
                if (sum + k < midPower)
                    return false;
                else
                {
                    if (i + r < totalCity)
                        stations[i + r] += midPower - sum;
                    k -= midPower - sum;
                    sum = midPower;
                }
            }
        }

        return true;
    }

public:
    static long long maxPower(const std::vector<int> &stations, const int &r, const int &k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int totalCity = stations.size();
        long long lowestPower = *std::min_element(stations.begin(), stations.end());
        long long maxPower = std::accumulate(stations.begin(), stations.end(), 0ll) + k, midPower{};
        long long ans{};

        while (lowestPower <= maxPower)
        {
            midPower = lowestPower + (maxPower - lowestPower) / 2;
            if (canObtain(stations, midPower, r, k))
                ans = midPower,
                lowestPower = midPower + 1;
            else
                maxPower = midPower - 1;
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int>
        vec = {1,
               2,
               4,
               5,
               0};
    std::cout << Solution::maxPower(vec, 1, 2) << std::endl;
    return 0;
}
