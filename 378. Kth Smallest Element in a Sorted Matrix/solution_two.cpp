#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
    /**
     * Normal Sorting after storing all the elements in a single vector
     * O(n*mlog(n*m)) Time Complexity;
     */
public:
    static int kthSmallest(const std::vector<std::vector<int>> &matrix, const int &k)
    {
        if (k == 1)
            return matrix.front().front();

        std::vector<int> numbers;
        for (int i = 0; i < matrix.size(); i++)
            numbers.insert(numbers.cend(), matrix.at(i).cbegin(), matrix.at(i).cend());

        std::sort(numbers.begin(), numbers.end());
        return numbers.at(k - 1);
    }
};

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> nums = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    std::cout
        << "ans " << Solution::kthSmallest(nums, 8);
    return 0;
}
