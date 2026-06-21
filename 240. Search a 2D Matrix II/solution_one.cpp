#include <vector>

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, const int &target)
    {
        int left, right, mid;
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix.at(i).front() > target)
                break;

            left = 0, right = matrix.at(i).size() - 1;
            while (left <= right)
            {
                mid = left + (right - left) / 2;
                if (matrix.at(i).at(mid) == target)
                {
                    matrix.clear();
                    return true;
                }
                else if (matrix.at(i).at(mid) > target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }

        return false;
    }
};
