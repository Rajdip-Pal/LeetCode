#include <iostream>
#include <vector>
#include <array>

class Solution
{
public:
    static int trap(const std::vector<int> &height)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int result{};
        std::vector<int> leftToRight(height.size());
        std::vector<int> rightToLeft(height.size());

        int start{};
        for (int i = 1; i < leftToRight.size(); i++)
            if (height[i] >= height[start])
                start = i;
            else
                leftToRight[i] = height[start] - height[i];

        start = height.size() - 1;
        for (int i = height.size() - 2; i >= 0; i--)
            if (height[i] >= height[start])
                start = i;
            else
                rightToLeft[i] = height[start] - height[i];

        for (int i = 0; i < height.size(); i++)
            result += std::min(leftToRight[i], rightToLeft[i]);

        return result;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> vec = {11, 679};
    std::cout << Solution::trap(vec) << std::endl;
    return 0;
}
