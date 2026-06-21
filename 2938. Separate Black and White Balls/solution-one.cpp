#include <iostream>
#include <string>

class Solution {
public:
    long long minimumSteps(const std::string& str) {
        std::ios::sync_with_stdio(0);
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);
        int start_index = 0, end_index = str.length() - 1;
        long long result {};
        while (start_index < end_index) {
            while (str[start_index] != '1' && start_index < end_index)
                start_index++;
            while (str[end_index] != '0' && end_index > start_index)
                end_index--;
            result += end_index-start_index;
            start_index++, end_index--;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
