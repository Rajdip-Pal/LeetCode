#include <ios>
#include <iostream>
#include <vector>

class Solution {
public:
  bool canSortArray(std::vector<int> &nums) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<int> setBit;
    setBit.reserve(nums.size());

    for (int i : nums)
      setBit.push_back(__builtin_popcount(std::move(i)));

    int previousSubArrayMaxElement{0}, maxElement{nums.at(0)},
        minElement{nums.at(0)};

    for (int i = 1; i < nums.size(); ++i) {
      if (setBit.at(i) == setBit.at(i - 1)) {
        maxElement = std::max(maxElement, nums.at(i));
        minElement = std::min(minElement, nums.at(i));
      } else {
        if (previousSubArrayMaxElement > minElement)
          return false;
        previousSubArrayMaxElement = maxElement;
        maxElement = nums.at(i);
        minElement = nums.at(i);
      }
    }
    if (previousSubArrayMaxElement > minElement)
      return false;

    return true;
  }
};
