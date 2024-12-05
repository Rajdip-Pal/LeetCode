#include <iostream>
#include <vector>
#include <numeric>

class Solution
{
public:
    int candy(const std::vector<int> &ratings)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        std::vector<int> candies(ratings.size(), 1);
        std::vector<int>::iterator straight = candies.begin() + 1;
        std::vector<int>::reverse_iterator reverse = candies.rbegin() + 1;
        std::vector<int>::const_iterator ratings_straight = ratings.begin() + 1;
        std::vector<int>::const_reverse_iterator ratings_reverse = ratings.rbegin() + 1;

        for (auto straigth_iter = candies.begin(); straight != candies.end(); straight++, ratings_straight++)
            if (*ratings_straight > *(ratings_straight - 1))
                *straight = *(straight - 1) + 1;

        for (; reverse != candies.rend(); reverse++, ratings_reverse++)
            if (*ratings_reverse > *(ratings_reverse - 1))
                *reverse = std::max(*reverse, *(reverse - 1) + 1);

        return std::accumulate(candies.begin(), candies.end(), 0);
    };
};

// [100, 80, 70, 60, 70, 80, 90, 100, 90, 80, 70, 60, 60]
