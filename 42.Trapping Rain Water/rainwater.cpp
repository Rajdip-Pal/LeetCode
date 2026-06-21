#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void display(int *ptr, int length){
    for (int i = 0; i < length; i++){
        cout << ptr[i] << " ";
    }
    cout << endl;
}

int trapped_water(vector<int>& height){
    int result {};
    int left_max_height[height.size()], right_max_height[height.size()];
    for (int i = 0; i < height.size(); i++){
        if (i == 0 || height[i] >= left_max_height[i - 1])
            left_max_height[i] = height[i];
        else
            left_max_height[i] = left_max_height[i - 1];
    }
    for (int i = height.size() - 1; i >= 0; i--)
    {
        if (i == height.size() - 1 || height[i] >= right_max_height[i + 1])
            right_max_height[i] = height[i];
        else
            right_max_height[i] = right_max_height[i + 1];
    }
    for (int i = 0; i < height.size(); i++)
        result += min(left_max_height[i],right_max_height[i]) - height[i];

    return result;
}



int main() {
    int n, userInput;
    cin>>n;
    vector<int> height;
    for (int i = 0; i < n; i++)
    {
        cin >> userInput;
        height.push_back(userInput);
    }
    std::cout << trapped_water(height);
    return 0;
}