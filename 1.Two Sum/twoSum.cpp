#include<iostream>
#include<vector>

std::vector<int> finding_pair(std::vector<int>& example,const int target){
    for (int i = 0; i < example.size(); i++)
        for (int j = 0; j < example.size(); j++)
            if (i == j) 
                continue;
            else{
                if (example[i] + example[j] == target)
                {
                    std::vector<int> result {i,j};
                    return result;
                }
            }

    std::vector<int> result;
    return result;
}

void printVector(std::vector<int> example){
    if (example.empty())
    {
        std::cout << "Empty";
        return;
    }
    for (int i = 0; i < example.size(); i++)
        std::cout << example[i] << " ";
}

int main() {
    std::vector<int> ok {1,2,3,4,5,6,7,8,9,10};
    printVector(finding_pair(ok,10));
    return 0;
}