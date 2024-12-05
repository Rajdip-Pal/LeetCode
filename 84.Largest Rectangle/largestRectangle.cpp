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

int main() {
    std::vector<int> heights = {2,1,3,5,6,2,3};
    std::cout << max_area(heights);

    return 0;
}