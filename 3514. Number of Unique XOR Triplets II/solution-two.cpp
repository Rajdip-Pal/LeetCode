#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iostream>

class Solution
{
    static const int max_xor = 2048;

public:
    int uniqueXorTriplets(std::vector<int> &nums)
    {
        const int n = nums.size();

        std::bitset<max_xor> temp, xors;

        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                temp[nums[i] ^ nums[j]] = 1;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < max_xor; j++)
                if (temp[j])
                    xors[nums[i] ^ j] = 1;

        return xors.count();
    }
};