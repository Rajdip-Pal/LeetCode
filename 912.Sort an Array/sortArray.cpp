#include<iostream>
#include<vector>

void merger(std::vector<int>& example, int start, int mid, int end){
    int first_array = mid - start + 1 ;
    int second_array = end - mid ;
    int index_main {start};
    int index_1 {}, index_2 {};

    int *_sub_array_1 = (int *)calloc(first_array,sizeof(int)),
        *_sub_array_2 = (int *)calloc(second_array,sizeof(int));

    for (int i = start; i <= end; i++)
        if (i < mid+1)
            _sub_array_1[i - start] = example[i];
        else
            _sub_array_2[i - mid - 1] = example[i];

    while ( index_1 < first_array && index_2 < second_array)
        if (_sub_array_1[index_1] <= _sub_array_2[index_2])
            example[index_main++] = _sub_array_1[index_1++];
        else
            example[index_main++] = _sub_array_2[index_2++];
    
    while (index_1<first_array)
        example[index_main++] = _sub_array_1[index_1++];

    while (index_2<second_array)
        example[index_main++] = _sub_array_2[index_2++];

    free(_sub_array_1);
    free(_sub_array_2);
}

void mergeSort(std::vector<int>& example,int begin,int end){
    if (begin >= end)   return;
    int mid = begin + (end - begin)/2;
    mergeSort(example,begin,mid);
    mergeSort(example,mid+1,end);
    merger(example,begin,mid,end);
}

int main() {
    int n , element;
    std::cin >> n;

    std::vector<int> trial;
    for (int i = 0; i < n; i++)
    {
        std::cin >> element;
        trial.push_back(element);
    }
    
    mergeSort(trial,0,n-1);

    for (int i = 0; i < n; i++)
        std::cout << trial[i] << " ";
        std::cout << std::endl;

    return 0;
}