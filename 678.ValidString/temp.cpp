#include<iostream>
#include <stack>

int main() {
    std::stack <int> trial;
    trial.push(10);
    trial.push(20);
    std::cout <<  trial.size();
    return 0;
}