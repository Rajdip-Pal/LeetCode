#include <vector>

class Solution {
public:
  int findMin(std::vector<int> &nums) {
    int left = 0, right = nums.size() - 1, mid;
    int ans = nums.front();

    while (left <= right) {
      mid = left + (right - left) / 2;
      ans = std::min(ans, nums.at(mid));

      if (nums.at(mid) >= nums.at(0))
        left = mid + 1;
      else
        right = mid - 1;
    }

    return ans;
  }
};
