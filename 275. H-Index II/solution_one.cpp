#include <vector>

class Solution
{
public:
    int hIndex(const std::vector<int> &citations)
    {
        if (citations.back() == 0)
            return 0;
        if (citations.front() >= citations.size())
            return citations.size();

        int distance, hindex = 1;
        std::vector<int>::const_iterator left = citations.cbegin(), right = citations.cend(), mid;
        while (left <= right)
        {
            mid = left + std::distance(left, right) / 2;
            distance = std::distance(mid, citations.end());
            if (*mid >= distance)
                hindex = std::max(hindex, distance), right = mid - 1;
            else
                left = mid + 1;
        }

        return hindex;
    }
};
