#include <queue>
#include <vector>

class Solution
{
    /**
     * Heap Solution;
     * O(n*mlogk) time;
     */
public:
    int kthSmallest(std::vector<std::vector<int>> &matrix, const int &k)
    {
        std::priority_queue<int> minHeap;

        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix.at(i).size(); j++)
                if (minHeap.push(matrix.at(i).at(j)); minHeap.size() > k)
                    minHeap.pop();

        return minHeap.top();
    }
};
