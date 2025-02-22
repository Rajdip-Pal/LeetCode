#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, const int &target)
    {
        std::unordered_map<int, std::vector<int>> value_index;
        for (int i = 0; i < nums.size(); i++)
            if (value_index.find(nums.at(i)) != value_index.cend())
                value_index[nums.at(i)].push_back(i);
            else
                value_index[nums.at(i)] = {i};

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums.at(i);
            if (value_index.find(complement) != value_index.cend())
            {
                if (complement == nums.at(i))
                    if (value_index[complement].size() > 1)
                        return {value_index[complement].at(0), value_index[complement].at(1)};
                    else
                        continue;
                else
                    return {i, value_index[complement].at(0)};
            }
        }
        return {};
    }
};

int main()
{
    std::cout << "__cplusplus: " << __cplusplus << std::endl;

    std::vector<int> vec(100, 10);
    std::cout << *vec.end() << std::endl;
    std::cout << *(vec.end() - 1) << std::endl;

    return 0;
}
