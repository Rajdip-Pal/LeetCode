#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution
{
public:
    std::vector<std::vector<int>> minimumAbsDifference(std::vector<int> &arr)
    {
        std::sort(arr.begin(), arr.end());
        std::vector<std::vector<int>> res;

        int minDiff = arr[1] - arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] != arr[i - 1])
            {
                int diff = arr[i] - arr[i - 1];

                if (diff == minDiff)
                    res.push_back({arr[i - 1], arr[i]});
                else if (diff < minDiff)
                {
                    minDiff = diff;
                    res = std::vector<std::vector<int>>();
                    res.push_back({arr[i - 1], arr[i]});
                }
            }
        }

        return res;
    }
};