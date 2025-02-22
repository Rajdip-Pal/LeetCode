#include <algorithm>
#include <set>
#include <vector>

class Solution
{
public:
    std::vector<int> intersection(const std::vector<int> &nums1, const std::vector<int> &nums2)
    {
        std::set<int> set1(nums1.cbegin(), nums1.cend()), set2(nums2.cbegin(), nums2.cend());
        std::vector<int> sorted_nums1(set1.cbegin(), set1.cend()), sorted_nums2(set2.cbegin(), set2.cend());
        std::vector<int> result;

        for (int i = 0; i < sorted_nums1.size(); i++)
            if (std::binary_search(sorted_nums2.cbegin(), sorted_nums2.cend(), sorted_nums1.at(i)))
                result.push_back(sorted_nums1.at(i));

        return result;
    }
};
