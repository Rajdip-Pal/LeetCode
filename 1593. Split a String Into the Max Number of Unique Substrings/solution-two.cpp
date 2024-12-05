#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
#include <algorithm>

/**
 * Solution 1593. Split a String Into the Max Number of Unique Substrings
 *
 * @Start
 */

class Solution
{
    static void recursiveSearch(const int &index, const std::string &str, std::unordered_set<std::string> &subStrCollections, const int &split, int &maxSplit)
    {
        if (split + (str.length() - index) > maxSplit)
            if (index == str.length())
                maxSplit = std::max(maxSplit, split);
            else
                for (int i = index; i < str.length(); i++)
                {
                    std::string subStr = str.substr(index, i - index + 1);
                    if (subStrCollections.find(subStr) == subStrCollections.end())
                    {
                        subStrCollections.insert(subStr);
                        recursiveSearch(i + 1, str, subStrCollections, split + 1, maxSplit);
                        subStrCollections.erase(subStr);
                    }
                }
    }

public:
    static int maxUniqueSplit(const std::string &str)
    {
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);

        int maxSplit{};
        std::unordered_set<std::string> collection;
        recursiveSearch(0, str, collection, 0, maxSplit);
        return maxSplit;
    }
};

/**
 * @End
 */

int main(int argc, char const *argv[])
{
    std::string str = "rajdip pal";
    std::cout << Solution::maxUniqueSplit(str);
    return 0;
}
