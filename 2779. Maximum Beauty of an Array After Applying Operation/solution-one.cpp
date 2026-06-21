#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int maximumBeauty(std::vector<int>& numbers, const int& k) {
        std::ios::sync_with_stdio(0);
        std::cin.tie(0);

        int length = numbers.size();
        int start_ptr{}, end_ptr{};
        int max_sequence{1}, sequence_length{};
        std::vector<int> start(length), end(length);

        std::sort(numbers.begin(), numbers.end());
        for (int i = 0; i < length; i++) {
            start[i] = numbers[i] + k;
            end[i] = numbers[i] - k;
        }

        while (start_ptr < length && end_ptr < length) {
            if (start[start_ptr] >= end[end_ptr])
                end_ptr++;
            else
                start_ptr++;
            max_sequence = std::max(max_sequence, end_ptr - start_ptr);
        }

        return max_sequence;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    std::vector<int> numbers = {4,6,1,2};
    int k = 2;
    std::cout << "Maximum beauty: " << solution.maximumBeauty(numbers, k) << std::endl;

    return 0;
}
