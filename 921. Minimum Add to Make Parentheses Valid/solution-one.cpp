#include <iostream>
#include <stack>

class Solution {
    int count(const std::string& str, char _main, char _aux) {
        int count {};
        std::stack<char> st;
        for (auto &&i : str) {
            if (i == _main)
                st.push(_main);
            else if (i == _aux) {
                if (st.empty())
                    count++;
                else
                    st.pop();
            }
        }
        return count + st.size();
    }

public:
    int minAddToMakeValid(const std::string& str) {
        return count(str,'(', ')');
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
