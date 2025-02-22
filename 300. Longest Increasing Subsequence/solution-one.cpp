#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int lengthOfLIS(std::vector<int> &nums)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        // O(n^2)

        if (nums.size() == 1)
            return 1;
        if (nums.size() == 2)
        {
            if (nums.front() < nums.back())
                return 2;
            return 1;
        }

        std::vector<int> LIS_List(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++)
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i])
                    LIS_List[i] = std::max(LIS_List[i], LIS_List[j] + 1);

        return *std::max_element(LIS_List.begin(), LIS_List.end());
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
