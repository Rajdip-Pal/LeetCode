#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution
{
public:
    int hIndex(std::vector<int> &citations)
    {
        if (citations.size() == 1)
        {
            if (citations.front() >= 1)
                return 1;
            return 0;
        }
        std::sort(citations.begin(), citations.end());

        for (int i = 0; i < citations.size(); i++)
            if (citations[i] >= citations.size() - i)
                return citations.size() - i;

        return 0;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}

/*

3 0 6 1 5

0 1 3 5 6


 */
