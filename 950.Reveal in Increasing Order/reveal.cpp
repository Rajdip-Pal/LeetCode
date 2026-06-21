#include<bits/stdc++.h>

std::vector<int> orderNeeded(std::vector<int>& deck){
    std::sort(deck.begin(), deck.end());
    std::queue<int> needed_order;
    for (int i = deck.size() - 1; i >= 0; i--){
        if (needed_order.empty())
            needed_order.push(deck[i]);
        else{
            needed_order.push(needed_order.front());
            needed_order.pop();
            needed_order.push(deck[i]);
        }      
    }

    for (int i = deck.size() - 1; i >= 0; i--){
        deck[i] = needed_order.front();
        needed_order.pop();
    }
    return deck;
}

int main() {
    int n , element;
    std::vector<int> trial;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> element;
        trial.push_back(element);
    }
    
    trial = orderNeeded(trial);

    for (int i = 0; i < trial.size(); i++)
        std::cout << trial[i] << " ";
    
    return 0;
}