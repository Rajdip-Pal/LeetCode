#include <algorithm>
#include <vector>

class Solution
{
public:
    int lengthOfLIS(const std::vector<int> &nums)
    {
        std::vector<int>::iterator lb;
        std::vector<int> sub_sequence;
        sub_sequence.reserve(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            lb = std::lower_bound(sub_sequence.begin(), sub_sequence.end(), nums.at(i));
            if (lb == sub_sequence.end())
                sub_sequence.push_back(nums.at(i));
            else
                *lb = nums.at(i);
        }

        sub_sequence.shrink_to_fit();
        return sub_sequence.size();
    }
};
