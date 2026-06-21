#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>

class Solution {
public:
    long long maxKelements(std::vector<int> &nums, int k) {
        long long result{}, item {};
        std::priority_queue<int> s(nums.begin(), nums.end());

        while (k--) {
            item = s.top();
            result += item;
            s.pop();
            s.push(std::ceil(static_cast<double>(item) / 3));
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    std::vector<int> nums = {1, 2, 3, 3, 3, 4, 8, 9, 15, 84, 95, 5, 6, 7};
    int k = 3;
    solution.maxKelements(nums, k);
    return 0;
}
