#include<iostream>
#include<stack>

std::string smallestNumber(std::string example,int k){
    if (example.size() <= k)
        return "0";
    
    std::stack<char> numbers;
    std::stack<char> resultStack;
    
    for(int i {}; i < example.size() ; ++i){
        if (numbers.empty())
            numbers.push(example[i]);
        else{
            while (numbers.top() > example[i])
            {
                if (k == 0) break;
                numbers.pop();
                k--;
                if (numbers.empty())    break;
            }
            numbers.push(example[i]);
        }
    }

    while (k != 0){
        if (numbers.empty())    break;
        numbers.pop();
        k--;
    }

    while (!numbers.empty()){
        resultStack.push(numbers.top());
        numbers.pop();
    }
    while (!resultStack.empty() && (resultStack.top() == '0'))
        resultStack.pop();

    if (resultStack.empty())
        return "0";
    else{
        std::string result {""};
        while (!resultStack.empty()){
            result += resultStack.top();
            resultStack.pop();
        }
        return result;
    }   
}

/* 10200  k=1
    Stack :: 
        1
        0
        02
        020
        0200
        200
*/

/* 12345  k = 3
    Stack :: 
        1
        12
        123
        1234
        12345
        1234
        123
        12
*/


int main() {
    
    int k;
    std::cin >> k;
    std::string trial;
    std::cin>>trial;
    std::cout << smallestNumber(trial, k);
    return 0;
}