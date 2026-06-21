#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <iomanip>

/**
 * Solution 1106. Parsing A Boolean Expression
 *
 * @Start
 */

class Solution {
    static std::pair<int, int> bracket_sequence(std::stack<int>& temp_stack,
                                                int& index,
                                                const std::string& expression) {
        int string_length = expression.length();

        for (true; index < string_length; index++)
            if (expression[index] == '(')
                temp_stack.push(index);
            else if (expression[index] == ')')
                return std::make_pair(temp_stack.top(), index);

        if (!temp_stack.empty())
            return std::make_pair(temp_stack.top(), string_length - 1);

        return std::make_pair(-1, -1);
    }

public:
    static bool parseBoolExpr(std::string& expression) {
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);

        int index{};
        bool isTrue = true;
        std::pair<int, int> bracket;
        std::stack<int> tempStack;
        std::string t = "t", f = "f";

        while (true) {
            isTrue = true;
            bracket = bracket_sequence(tempStack, index, expression);

            if (!tempStack.empty())
                tempStack.pop();

            if (!tempStack.empty())
                index = tempStack.top() + 1;
            else
                index = 0;

            if (bracket == std::make_pair(-1, -1))
                break;

            if (expression[bracket.first - 1] == '!') {
                if (expression[bracket.first + 1] == 't')
                    expression.replace(expression.begin() + bracket.first - 1,
                                       expression.begin() + bracket.second + 1,
                                       f.begin(), f.end());
                else if (expression[bracket.first + 1] == 'f')
                    expression.replace(expression.begin() + bracket.first - 1,
                                       expression.begin() + bracket.second + 1,
                                       t.begin(), t.end());
            } else if (expression[bracket.first - 1] == '|') {
                for (int i = bracket.first + 1; i < bracket.second; i++)
                    if (expression[i] == 't') {
                        isTrue = false;
                        expression.replace(
                            expression.begin() + bracket.first - 1,
                            expression.begin() + bracket.second + 1, "t");
                        break;
                    }

                if (isTrue)
                    expression.replace(expression.begin() + bracket.first - 1,
                                       expression.begin() + bracket.second + 1,
                                       "f");
            } else if (expression[bracket.first - 1] == '&') {
                for (int i = bracket.first + 1; i < bracket.second; i++)
                    if (expression[i] == 'f') {
                        isTrue = false;
                        expression.replace(
                            expression.begin() + bracket.first - 1,
                            expression.begin() + bracket.second + 1, f.begin(),
                            f.end());
                        break;
                    }
                if (isTrue)
                    expression.replace(expression.begin() + bracket.first - 1,
                                       expression.begin() + bracket.second + 1,
                                       "t");
            }
        }

        if (expression == "t")
            return true;
        else
            return false;
    }
};

/**
 * @End
 */

int main(int argc, char const *argv[])
{

    std::string expression = "!(|(&(f,t),f))";
    std::cout << std::boolalpha << Solution::parseBoolExpr(expression) << std::endl;
    return 0;
}
