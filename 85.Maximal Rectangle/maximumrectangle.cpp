#include<iostream>
#include<vector>
#include<stack>

int max_area(std::vector<int>& heights){
    int length = heights.size(), max_area {};
    std::stack<int> smaller;
    int *_left_boundary = (int *)malloc(length*sizeof(int));
    int *_right_boundary = (int *)malloc(length*sizeof(int));
    for(int i = 0; i < length; i++){
        while(!smaller.empty() && heights[smaller.top()] >= heights[i])
            smaller.pop();
        if (smaller.empty())    _left_boundary[i] = 0;
        else    _left_boundary[i] = smaller.top() + 1;
        smaller.push(i);
    }
    while (!smaller.empty())    smaller.pop();
    for (int i = length - 1; i >= 0; i--){
        while ( !smaller.empty() && heights[i] <= heights[smaller.top()])
            smaller.pop();
        if (smaller.empty())    _right_boundary[i] = length - 1;
        else    _right_boundary[i] = smaller.top() - 1;
        smaller.push(i);
    }
    max_area = (_right_boundary[0] - _left_boundary[0] + 1 ) * heights[0];
    for (int i = 1; i < length; i++)
        max_area = std::max(max_area,(_right_boundary[i] - _left_boundary[i] + 1) * heights[i]);
    free(_left_boundary),free(_right_boundary);
    return max_area;
}

int possible_max_area(std::vector<std::vector<char>>& matrix){
    int length = matrix[0].size();
    int possible_max_area {};
    std::vector<int> temp(length);
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < length; j++){
            if (matrix[i][j] == '1')
                temp[j] += 1;
            else
                temp[j] = 0;
        }
        if ( i == 0 ) {
            possible_max_area = max_area(temp);
            continue;
        }
        possible_max_area = std::max(possible_max_area,max_area(temp));
    }
    return possible_max_area;
}

int main() {
    char arr1[] = {'1','1','0','1','0'};
    char arr2[] = {'1','0','0','1','0'};
    std::vector<char> ok1,ok2;
    ok1.assign(arr1,arr1+5);
    ok2.assign(arr2,arr2+5);
    std::vector<std::vector<char>> temp;
    temp.push_back(ok1);
    temp.push_back(ok2);

    std::cout << "\n" << possible_max_area(temp);
    return 0;
}