#include <iostream>
#include <vector>

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        if (prices.size() < 2)
            return std::max(0, prices.back() - prices.front());
        else
        {
            int maximumPossibleProfit{};
            int sellPrice{prices[0]}, buyPrice{prices[0]};

            for (int i{1}; i < prices.size(); i++)
            {
                if (prices[i] < buyPrice)
                    sellPrice = buyPrice = prices[i];
                else if (prices[i] > sellPrice)
                {
                    sellPrice = prices[i];
                    maximumPossibleProfit = std::max(maximumPossibleProfit, sellPrice - buyPrice);
                }
            }

            return maximumPossibleProfit;
        }
    }
};
