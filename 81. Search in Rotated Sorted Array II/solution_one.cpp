#include <vector>

class Solution {
public:
  bool search(const std::vector<int> &nums, const int &target) {
    int left = 0, right = nums.size() - 1, mid;

    while (left <= right) {
      mid = left + (right - left) / 2;
      if (nums.at(mid) == target)
        return true;

      if (nums.at(mid) == nums.at(left))
        while (left < mid and nums.at(++left) == nums.at(mid))
          ;

      if (nums.at(mid) == nums.at(right))
        while (right > mid and nums.at(--right) == nums.at(mid))
          ;

      if (nums.at(mid) >= nums.at(left)) {
        if (target >= nums.at(left) and target < nums.at(mid))
          right = mid - 1;
        else
          left = mid + 1;
      } else {
        if (target <= nums.at(right) and target > nums[mid])
          left = mid + 1;
        else
          right = mid - 1;
      }
    }

    return false;
  }
};