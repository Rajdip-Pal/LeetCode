#include <iostream>
#include <vector>

class Solution
{
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
    {
        std::vector<int> finalSortedArray;
        finalSortedArray.reserve(n + m);

        int i{}, j{};
        while (i < m and j < n)
            if (nums1[i] < nums2[j])
                finalSortedArray.push_back(nums1[i++]);
            else
                finalSortedArray.push_back(nums2[j++]);

        while (i < m)
            finalSortedArray.push_back(nums1[i++]);
        while (j < n)
            finalSortedArray.push_back(nums2[j++]);

        nums1.assign(finalSortedArray.begin(), finalSortedArray.end());
    }
};
