#include <algorithm>
#include <vector>

using ::std::vector;

class Solution
{
public:
    int minimumSize(const vector<int> &nums, const int &maxOperations)
    {

        auto can_divide = [&](const int &maxBalls) -> bool
        {
            int operations{};
            for (int i = 0; i < nums.size(); i++)
            {
                operations += (nums[i] - 1) / maxBalls;
                if (operations > maxOperations)
                    return false;
            }
            return true;
        };

        int left = 1, right = *std::max_element(nums.cbegin(), nums.cend());
        int mid, result = right;

        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (can_divide(mid))
                result = mid, right = mid - 1;
            else
                left = mid + 1;
        }

        return result;
    }
};
