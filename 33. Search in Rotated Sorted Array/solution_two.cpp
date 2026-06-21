#include <vector>

class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, mid, ans = -1;

        while (left <= right)
            (nums[mid = left + (right - left) / 2] == target) ? (ans = mid, left = right + 1) : ((nums[left] <= nums[mid]) ? ((nums[left] <= target && target < nums[mid]) ? right = mid - 1 : left = mid + 1) : ((nums[mid] < target && target <= nums[right]) ? left = mid + 1 : right = mid - 1));

        return ans;
    }
};
