#include <vector>

class Solution
{
public:
  int findPeakElement(const std::vector<int> &nums)
  {
    if (nums.size() == 1)
      return nums.front();

    if (nums.front() > nums.at(1))
      return 0;
    if (nums.back() > nums.at(nums.size() - 2))
      return nums.size() - 1;

    int left = 1, right = nums.size() - 2, mid;
    while (left <= right)
    {
      mid = left + (right - left) / 2;
      if (nums.at(mid) > nums.at(mid - 1) and nums.at(mid) > nums.at(mid + 1))
      {
        return mid;
      }
      else if (nums.at(mid) > nums.at(mid - 1))
      {
        left = mid + 1;
      }
      else
      {
        right = mid - 1;
      }
    }

    return -1;
  }
};
