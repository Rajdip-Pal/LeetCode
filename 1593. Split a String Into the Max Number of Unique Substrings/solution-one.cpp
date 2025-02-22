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
    static int recursiveSearch(const int &index, const std::string &str, std::unordered_set<std::string> &subStrCollections)
    {
        int result{};
        if (index == str.length())
            return result;
        for (int i = index; i < str.length(); i++)
        {
            std::string subStr = str.substr(index, i - index + 1);
            if (subStrCollections.find(subStr) == subStrCollections.end())
            {
                subStrCollections.insert(subStr);
                result = std::max(result, 1 + recursiveSearch(i + 1, str, subStrCollections));
                subStrCollections.erase(subStr);
            }
        }
        return result;
    }

public:
    static int maxUniqueSplit(const std::string &str)
    {
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);

        std::unordered_set<std::string> collection;
        return recursiveSearch(0, str, collection);
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
