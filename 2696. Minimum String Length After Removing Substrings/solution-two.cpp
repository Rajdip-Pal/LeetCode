#include <iostream>
#include <stack>

class Solution {
public:
    int minLength(std::string& str) {
        int length = str.length();
        std::stack<char> letters;
        for (int i = 0; i < length ; i++) {
            if (letters.empty())
                letters.push(str[i]);
            else if (str[i] == 'B' and letters.top() == 'A')
                letters.pop();
            else if (str[i] == 'D' and letters.top() == 'C')
                letters.pop();
            else
                letters.push(str[i]);
        }
        return letters.size();
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    std::string str = "ACBBD";
    std::cout << solution.minLength(str) << std::endl;
    return 0;
}
