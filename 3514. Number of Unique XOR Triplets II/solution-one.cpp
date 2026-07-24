#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution
{
public:
    int uniqueXorTriplets(std::vector<int> &nums)
    {
        const int n = nums.size();
        std::unordered_set<int> temp, xors;

        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                temp.insert(nums[i] ^ nums[j]);

        std::vector<int> t(temp.begin(), temp.end());
        for (int i = 0; i < n; i++)
            for (int j = 0; j < t.size(); j++)
                xors.insert(nums[i] ^ t[j]);

        return xors.size();
    }
};