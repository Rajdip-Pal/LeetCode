#include<iostream>
#include<stack>

std::string validString(const std::string example){
    std::string temp {example};
    std::string result {""};
    // std::stack<char> symbols;
    std::stack<int> indexStack;
    for (int i = 0; i < temp.length(); i++)
    {
        if (temp[i] == '(')
        {
            // symbols.push(example[i]);
            indexStack.push(i);
        }
        else if (temp[i] == ')')
        {
            if (indexStack.empty())
            {
                temp[i] = ' ';
            }
            else{
                // symbols.pop();
                indexStack.pop();
            }
        }
    }

    while (!indexStack.empty()){
        int location = indexStack.top();
        temp[location] = ' ';
        indexStack.pop();
    }

    for (int i = 0; i < temp.length();i++)
    {
        if (temp[i] == ' ') continue;
        result += temp[i];
    }

    return result;
}

int main() {
    std::string str;
    std::getline(std::cin,str);
    std::cout << validString(str);
    return 0;
}