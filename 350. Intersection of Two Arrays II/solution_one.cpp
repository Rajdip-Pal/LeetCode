#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    static std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        std::vector<int>::const_iterator pointer_nums1 = nums1.cbegin(), pointer_nums2 = nums2.cbegin();
        std::vector<int> result;

        while (pointer_nums1 != nums1.cend() and pointer_nums2 != nums2.cend())
        {
            if (*pointer_nums1 == *pointer_nums2)
                result.push_back(*pointer_nums1),
                    nums1.erase(pointer_nums1),
                    nums2.erase(pointer_nums2);
            else if (*pointer_nums1 > *pointer_nums2)
                pointer_nums2++;
            else
                pointer_nums1++;
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> nums1 = {1, 2, 3, 3, 4, 5, 6, 7, 8, 9},
                     nums2 = {1, 3, 3, 5, 7, 9};

    std::vector<int> result = Solution::intersect(nums1, nums2);

    for (auto &&i : result)
        std::cout << i << " ";

    return 0;
}
