#include<iostream>
#include<queue>

short numberOfStudentsUnableToEatCount(std::queue<int> students, std::queue<int> sandwich){
    short count = 0;
    while (!students.empty())
    {
        if (students.front() == sandwich.front())
        {
            students.pop();
            sandwich.pop();
            count = 0;
        }
        else{
            students.push(students.front());
            students.pop();
            count++;
        }
        if (count >= students.size()) break;
    }
    return students.size();
}

int main() {
    std::queue<int>  students;
    students.push(1);
    students.push(1);
    students.push(1);
    students.push(0);
    students.push(0);
    students.push(1);

    std::queue<int>  sandwich;
    sandwich.push(1);
    sandwich.push(0);
    sandwich.push(0);
    sandwich.push(0);
    sandwich.push(1);
    sandwich.push(1);

    std::cout<< numberOfStudentsUnableToEatCount(students,sandwich) << "\n" ;

    return 0;
}