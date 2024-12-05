#include <iostream>
#include <vector>

class Solution
{
public:
    int removeElement(std::vector<int> &nums, const int &val)
    {
        while (!nums.empty() and nums.back() == val)
            nums.pop_back();

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == val)
            {
                nums[i] = nums.back(), nums.pop_back();
                while (!nums.empty() and nums.back() == val)
                    nums.pop_back();
            }
        return nums.size();
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
