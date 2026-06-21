#include <vector>

class Solution
{
public:
    std::vector<int> spiralOrder(const std::vector<std::vector<int>> &matrix)
    {
        std::vector<int> result;
        result.reserve(matrix.size() * matrix.front().size());

        int i;
        int left = 0;
        int right = matrix.front().size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;

        while (left <= right && top <= bottom)
        {
            for (i = left; i <= right; ++i)
                result.push_back(matrix[top][i]);

            for (i = top + 1; i <= bottom; ++i)
                result.push_back(matrix[i][right]);

            if (top < bottom)
                for (i = right - 1; i >= left; --i)
                    result.push_back(matrix[bottom][i]);

            if (left < right)
                for (i = bottom - 1; i > top; --i)
                    result.push_back(matrix[i][left]);

            ++left, --right;
            ++top, --bottom;
        }

        return result;
    }
};
