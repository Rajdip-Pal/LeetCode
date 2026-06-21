#include <iostream>
#include <vector>

class Solution
{
public:
    int maxProfit(const std::vector<int> &prices)
    {
        if (prices.size() < 3)
            return std::max(0, prices.back() - prices.front());

        int totalProfit{};
        int buyPrice{}, sellPrice{};
        buyPrice = sellPrice = 0;

        while (buyPrice < prices.size() and sellPrice < prices.size())
        {
            while (sellPrice < prices.size() - 1 and prices[sellPrice + 1] >= prices[sellPrice])
                sellPrice++;

            totalProfit += prices[sellPrice] - prices[buyPrice];

            buyPrice = ++sellPrice;
        }

        return totalProfit;
    }
};
