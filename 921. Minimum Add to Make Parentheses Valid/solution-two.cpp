#include <iostream>
#include <stack>

class Solution {
public:
    int minAddToMakeValid(const std::string& str) {
        int count {}, length = str.length();
        std::stack<char> st;
        for (int i = 0; i < length; ++i) {
            if (str[i] == '(')
                st.push('(');
            else if (str[i] == ')' && st.empty())
                count++;
            else if (str[i] == ')')
                st.pop();
        }
        return count + st.size();
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
