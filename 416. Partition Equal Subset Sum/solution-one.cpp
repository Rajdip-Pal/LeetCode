#include <iostream>
#include <vector>

class Solution
{
public:
    bool canPartition(const std::vector<int> &nums)
    {
        int total_sum{};
        for (auto &&i : nums)
            total_sum += i;

        if (total_sum & 1)
            return false;
        else
            return true;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
