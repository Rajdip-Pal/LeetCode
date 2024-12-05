#include <algorithm>
#include <vector>

class Solution
{
    /**
     * Approach using Binary Search
     * O(nlog²(max-min))
     */
    int countLessEqual(int &count, const int &val, const std::vector<std::vector<int>> &matrix)
    {
        count = 0;
        for (int i = 0; i < matrix.size(); i++)
            if (matrix.at(i).back() <= val)
                count += matrix.at(i).size();
            else
                count +=
                    std::upper_bound(matrix.at(i).begin(), matrix.at(i).end(), val) - matrix.at(i).begin();

        return count;
    }

public:
    int kthSmallest(const std::vector<std::vector<int>> &matrix, const int &k)
    {
        int left = matrix.front().front();
        int right = matrix.back().back();
        int mid, count, ans;

        while (left <= right)
        {
            mid = left + (right - left) / 2;
            countLessEqual(count, mid, matrix);

            if (count >= k)
                ans = mid, right = mid - 1;
            else
                left = mid + 1;
        }

        return ans;
    }
};
