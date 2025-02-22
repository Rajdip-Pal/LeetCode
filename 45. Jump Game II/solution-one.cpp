#include <iostream>
#include <vector>

class Solution
{
public:
    int jump(std::vector<int> &nums)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        if (nums.size() < 2)
            return 0;
        if (nums.front() >= nums.size() - 1)
            return 1;

        int leftWindow = 0, rightWindow = 0, jumpCount = 0;
        for (int i = 0; i < nums.size() and rightWindow < nums.size() - 1; i++)
        {
            if (i > leftWindow and ++jumpCount)
                leftWindow = rightWindow;
            rightWindow = std::max(rightWindow, i + nums[i]);
        }
        return ++jumpCount;
    }
};

/*

[2,3,1,1,4]



 */
