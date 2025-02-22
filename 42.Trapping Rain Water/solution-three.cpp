#include <iostream>
#include <vector>

class Solution
{
public:
    static int trap(const std::vector<int> &height)
    {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        if (height.size() <= 2)
            return 0;

        int left = 0, right = height.size() - 1;
        int maxLeft = height[left], maxRight = height[right];
        int totalWater{};

        while (left < right)
        {
            if (maxLeft < maxRight)
            {
                left++;
                maxLeft = std::max(maxLeft, height[left]);
                totalWater += maxLeft - height[left];
            }
            else
            {
                right--;
                maxRight = std::max(maxRight, height[right]);
                totalWater += maxRight - height[right];
            }
        }

        return totalWater;
    }
};
