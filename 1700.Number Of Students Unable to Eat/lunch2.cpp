#include<iostream>
#include<vector>

int main() {
    std::vector<int> students {1,1,0,0};
    std::vector<int> sandwiches {0,1,0,1};
    int studentsNumberOf0 {}, studentsNumberOf1 {}; 
    int sandwichesNumberOf0 {}, sandwichesNumberOf1 {}; 
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i] == 0)   sandwichesNumberOf0++;
        else    sandwichesNumberOf1++;
        if (sandwiches[i] == 0) sandwichesNumberOf0++;
        else    studentsNumberOf1++;
    }
    if (sandwichesNumberOf0 == studentsNumberOf0);
    return 0;
}