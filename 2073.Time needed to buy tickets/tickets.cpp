#include<iostream>
#include<vector>

int timeNeeded(std::vector<int>& tickets, int position){
    int result {};
    for (int i = 0 ; tickets[position] != 0 ; i = (i+1) % tickets.size()){
        if (tickets[i] == 0)
            continue;
        tickets[i]--;
        result++;
    }
    return result;   
}

int main() {
    std::vector<int> tickets {5,1,1,1};
    int position {0};
    std::cout << timeNeeded(tickets,position);
    return 0;
}