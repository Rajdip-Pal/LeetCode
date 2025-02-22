#include <cmath>
#include <queue>
#include <vector>

class Solution
{
public:
    long long pickGifts(std::vector<int> &gifts, int k)
    {
        long long ans{};
        std::priority_queue<int> maxHeap(gifts.cbegin(), gifts.cend());
        for (int i = 0; i < k; i++)
            maxHeap.push(std::sqrt(maxHeap.top())), maxHeap.pop();
        while (!maxHeap.empty())
            ans += maxHeap.top(), maxHeap.pop();
        return ans;
    }
};
