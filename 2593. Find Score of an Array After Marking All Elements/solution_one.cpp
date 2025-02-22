#include <algorithm>
#include <vector>

class Solution
{
public:
    long long findScore(const std::vector<int> &nums)
    {
        int size = nums.size(), index;
        long long score = 0;
        std::vector<bool> visited(size, false);
        std::vector<std::pair<int, int>> indices(size);

        for (int i = 0; i < size; i++)
            indices[i] = std::pair<int, int>{nums[i], i};

        std::sort(indices.begin(), indices.end());

        for (int i = 0; i < size; i++)
        {
            index = indices[i].second;
            if (!visited[index])
            {
                score += indices[i].first;
                visited[index] = true;
                if (index > 0)
                    visited[index - 1] = true;
                if (index < size - 1)
                    visited[index + 1] = true;
            }
        }

        return score;
    }
};
