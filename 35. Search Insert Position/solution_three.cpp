#include <vector>

class Solution
{
    int lower_bound(std::vector<int> &nums, const int &start, const int &end, const int &target)
    {
        int left = start, right = end, mid;
        while (left < right)
            nums[mid = left + (right - left) / 2] < target ? left = mid + 1 : right = mid;
        return left;
    }

public:
    int searchInsert(std::vector<int> &nums, int target)
    {
        return lower_bound(nums, 0, nums.size(), target);
    }
};
