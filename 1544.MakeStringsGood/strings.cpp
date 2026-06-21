#include<iostream>

std::string goodString(std::string str){
    std::string tempString;
    for(short i {} ; i < str.length() ; i++)
    {
        if (str[i] == str[i+1] - ('a'-'A') || str[i] == str[i+1] + ('a'-'A')) {
            if (str[i] >= 'a'  && str[i] <= 'z') i++;
            else if (str[i] >= 'A'  && str[i] <= 'Z') i++;
            else continue;
        }
        else tempString += str[i];
    }
    return tempString;
}

bool isIt(std::string s){
    for(short i {} ; i < s.length() ; i++)
    {
        if (s[i] == s[i+1] - ('a'-'A') || s[i] == s[i+1] + ('a'-'A'))
            return false;
    }
    return true;
}

std::string makeGoodString(std::string s){
    std::string temp = s;
    while (!isIt(temp))
    {
        temp = goodString(temp);
    }
    return temp;
}

int main() {
    std::string str;
    std::getline(std::cin,str);

    std::cout << makeGoodString(str);
    return 0;
}