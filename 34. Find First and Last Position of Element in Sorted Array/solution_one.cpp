#include <vector>

class Solution
{
public:
    std::vector<int> searchRange(const std::vector<int> &nums, const int &target)
    {
        int start, end;

        int left = 0, right = nums.size() - 1, mid;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                start = end = mid;
                while (start > 0 and nums.at(start - 1) == nums.at(mid))
                    start--;
                while (end < nums.size() - 1 and nums.at(end + 1) == nums.at(mid))
                    end++;
                return std::vector<int>{start, end};
            }
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return std::vector<int>{-1, -1};
    }
};
