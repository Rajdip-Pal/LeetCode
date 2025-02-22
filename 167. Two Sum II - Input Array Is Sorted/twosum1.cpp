#include<iostream>
#include<vector>

std::vector<int> two_sum(const std::vector<int>& example, const int target){
    int left {}, right {(int)example.size() -1};
    while (left < right){
        if (example[left] + example[right] == target)
            return {left+1,right+1};
        else if (example[left] + example[right] < target)
            left ++;
        else if (example[left] + example[right] > target)
            right --;
    }
    return {};
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
    std::vector<int> trial;
    int n , element;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> element;
        trial.push_back(element);
    }
    std::cin >> n;

    printVector(two_sum(trial,n));
    
    return 0;
}