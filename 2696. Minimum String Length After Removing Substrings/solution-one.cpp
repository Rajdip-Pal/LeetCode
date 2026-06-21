#include <iostream>
#include <stack>

class Solution {
public:
    int minLength(std::string& str) {
        std::stack<char> letters;
        for (auto &&i : str) {
            if (letters.empty())
                letters.push(i);
            else if (i == 'B' and letters.top() == 'A')
                letters.pop();
            else if (i == 'D' and letters.top() == 'C')
                letters.pop();
            else
                letters.push(i);
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
