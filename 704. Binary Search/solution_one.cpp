#include <vector>

class Solution
{
    int binary_search(const std::vector<int> &arr, const int &start, const int &end, const int &target)
    {
        if (start > end)
            return -1;
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            return binary_search(arr, mid + 1, end, target);
        else
            return binary_search(arr, start, mid - 1, target);
    }

public:
    int search(std::vector<int> &nums, int target)
    {
        return binary_search(nums, 0, nums.size() - 1, target);
    }
};
