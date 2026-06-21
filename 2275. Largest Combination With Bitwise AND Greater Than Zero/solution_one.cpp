#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

auto init = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
};

class Solution
{
public:
    int largestCombination(const std::vector<int> &candidates)
    {
        std::array<int, 24> max_len_in_this_pos;
        std::vector<std::string> binary_number(candidates.size());

        for (int i = 0; i < binary_number.size(); i++)
            binary_number[i] = std::bitset<24>(candidates[i]).to_string();

        for (int i = 0; i < 24; i++)
            for (int j = 0; j < candidates.size(); j++)
                if (binary_number[j][i] == '1')
                    max_len_in_this_pos[i]++;

        return *std::max_element(max_len_in_this_pos.begin(), max_len_in_this_pos.end());
    }
};
