#include <unordered_map>
#include <vector>

class Solution
{
public:
    std::vector<int> intersect(const std::vector<int> &nums1, const std::vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);

        std::vector<int> result;
        std::unordered_map<int, int> frequency_map;
        for (int i = 0; i < nums1.size(); i++)
            frequency_map[nums1.at(i)]++;

        for (int i = 0; i < nums2.size(); i++)
            if (frequency_map.find(nums2.at(i)) != frequency_map.cend())
                if (frequency_map.at(nums2.at(i)) > 0)
                    result.push_back(nums2.at(i)),
                        frequency_map[nums2.at(i)]--;

        return result;
    }
};
