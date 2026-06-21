#include <iostream>
#include <stack>
#include <cmath>

class Solution {
public:
    int minSwaps(const std::string& str) {
        std::stack<char> brackets;
        int length = str.length();
        for (int i = 0; i < length; i++) {
            if (    
                    !brackets.empty() && 
                    (brackets.top() == '[' && str[i] == ']')
                ) 
            {
                brackets.pop();
                continue;
            }
            brackets.push(str[i]);
        }
        return static_cast<int>(std::ceil((brackets.size()/4.0)));
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    std::string str = "]]][[[";
    std::cout << solution.minSwaps(str) << std::endl; 
    return 0;
}
