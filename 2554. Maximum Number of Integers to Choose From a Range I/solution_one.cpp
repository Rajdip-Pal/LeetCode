#include <cstring>
#include <iostream>
#include <vector>

/*
    FUNCTION FOR DEBUG PURPOSE
*/

template <typename T>
std::ostream &operator<<(std::ostream &output, const std::vector<T> &obj)
{
    output << "[";
    for (int i = 0; i < obj.size() - 1; i++)
        output << obj.at(i) << ", ";
    output << obj.back() << "]";
    return output;
}

/*
    CODE START
*/

class Solution
{
    static bool nums[10001];

public:
    int maxCount(const std::vector<int> &banned, const int &n, const int &maxSum)
    {
        __builtin_memset(nums, true, n + 1);
        int total_sum{}, count{};

        for (int i = 0; i < banned.size(); i++)
            if (banned.at(i) <= n)
                nums[banned.at(i)] = false;

        for (int i = 1; i <= n; i++)
            if (nums[i])
            {
                if (total_sum + i <= maxSum)
                    total_sum += i, count++;
                else
                    break;
            }

        return count;
    }
};

bool Solution::nums[10001];

/*
    CODE END
*/
