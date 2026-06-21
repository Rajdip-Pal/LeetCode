#include <vector>

class Solution
{
public:
    int singleNonDuplicate(const std::vector<int> &nums)
    {
        int ans = 0;
        int start = 0, end = nums.size() - 1, mid;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            ans = nums.at(mid);
            if (mid < nums.size() - 1 and nums.at(mid) == nums.at(mid + 1))
                ((mid & 1) == 0) ? start = mid + 2 : end = mid - 1;
            else if (mid > 0 and nums.at(mid) == nums.at(mid - 1))
                ((mid & 1) == 1) ? start = mid + 1 : end = mid - 2;
            else
                break;
        }

        return ans;
    }
};
