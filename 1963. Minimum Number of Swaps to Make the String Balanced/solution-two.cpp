#include <iostream>
#include <stack>
#include <cmath>

class Solution {
public:
    int minSwaps(const std::string& str) {
        int length = str.length(), imbalacendePair{};

        for (int i = 0; i < length; i++) {
            if (str[i] == '[')
                imbalacendePair++;
            else if (imbalacendePair > 0)
                imbalacendePair--;
        }

        return ((imbalacendePair + 1) / 2);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    std::string str = "]]][[[";
    std::cout << solution.minSwaps(str) << std::endl; 
    return 0;
}
