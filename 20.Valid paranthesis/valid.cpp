#include<iostream>
#include<stack>

bool is_valid(std::string parenthesis){
    std::stack<char> temp;
    for (int i = 0; i < parenthesis.length(); i++){
        if ( parenthesis[i] == '(' || parenthesis[i] == '{' || parenthesis[i] == '[')
            temp.push(parenthesis[i]);
        else if (parenthesis[i] == ')' || parenthesis[i] == '}' || parenthesis[i] == ']'){
            if (temp.empty())   return false;
            if (temp.top() == '(' && parenthesis[i] == ')')
                temp.pop();
            else if (temp.top() == '{' && parenthesis[i] == '}')
                temp.pop();
            else if (temp.top() == '[' && parenthesis[i] == ']')
                temp.pop();
            else
                return false;
        }
    }
    if (temp.empty())
        return true;
    else
        return false;
}

int main() {
    std::string trial;
    std::getline(std::cin,trial);
    std::cout << std::boolalpha << is_valid(trial);
    return 0;
}