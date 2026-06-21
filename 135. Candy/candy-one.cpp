#include <iostream>
#include <vector>

class Solution
{
public:
    int candy(const std::vector<int> &ratings)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        // Don't know why but i was using two vectors here...

        int result{};
        std::vector<int> candies_straight(ratings.size(), 1);
        std::vector<int> candies_reverse(ratings.size(), 1);
        std::vector<int>::iterator straight_iter = candies_straight.begin() + 1;
        std::vector<int>::reverse_iterator reverse_iter = candies_reverse.rbegin() + 1;
        std::vector<int>::const_iterator ratings_straight = ratings.begin() + 1;
        std::vector<int>::const_reverse_iterator ratings_reverse = ratings.rbegin() + 1;

        for (auto straigth_iter = candies_straight.begin(); straight_iter != candies_straight.end(); straight_iter++, ratings_straight++)
            if (*ratings_straight > *(ratings_straight - 1))
                *straight_iter = *(straight_iter - 1) + 1;

        for (; reverse_iter != candies_reverse.rend(); reverse_iter++, ratings_reverse++)
            if (*ratings_reverse > *(ratings_reverse - 1))
                *reverse_iter = *(reverse_iter - 1) + 1;

        for (int i = 0; i < ratings.size(); i++)
            result += std::max(candies_straight[i], candies_reverse[i]);

        return result;
    };
};

// [100, 80, 70, 60, 70, 80, 90, 100, 90, 80, 70, 60, 60]
