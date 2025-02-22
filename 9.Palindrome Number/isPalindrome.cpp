#include<iostream>

bool isPalindrome(const int x){
    std::string temp = std::to_string(x);
    for (int i=0;i < temp.length()/2 ;++i)  
        if (temp[i] != temp[temp.length() -1-i])  
            return false; 
    return true;
}

int main() {
    int n;
    std::cin >> n ;
    std::cout << std::boolalpha << isPalindrome(n);
    return 0;
}