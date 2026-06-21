#include <vector>

class Solution
{
    int lower_bound(const std::vector<int> &nums, const int &start, const int &end, const int &target)
    {
        int left = start, right = end, mid;
        while (left < right)
            (nums[mid = left + (right - left) / 2] < target) ? left = mid + 1 : right = mid;

        return left;
    }

    int upper_bound(const std::vector<int> &nums, const int &start, const int &end, const int &target)
    {
        int left = start, right = end, mid;
        while (left < right)
            (nums[mid = left + (right - left) / 2] <= target) ? left = mid + 1 : right = mid;

        return left;
    }

public:
    std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        if (nums.empty())
            return std::vector({-1, -1});

        const int low = lower_bound(nums, 0, nums.size(), target), high = upper_bound(nums, 0, nums.size(), target);

        if (low == nums.size() || nums[low] != target)
            return std::vector({-1, -1});

        return std::vector({low, high - 1});
    }
};
