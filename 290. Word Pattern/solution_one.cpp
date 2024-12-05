#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    static std::vector<std::string> splitWhiteSpaceandCollectWords(const std::string &sentence)
    {
        std::string _;
        std::stringstream ss(sentence);
        std::vector<std::string> _temp;

        while (ss >> _)
            _temp.push_back(_);
        return _temp;
    }

public:
    bool wordPattern(const std::string &pattern, const std::string &sentence)
    {
        int patternMap[128] = {0};
        std::vector<std::string> words = splitWhiteSpaceandCollectWords(sentence);
        std::unordered_map<std::string, int> wordMap;

        if (pattern.size() != words.size())
            return false;

        int i = 0;
        while (i < pattern.length() and patternMap[pattern[i]] == wordMap[words[i]])
            patternMap[pattern[i]] = wordMap[words[i]] = i + 1, i++;

        if (i < pattern.length())
            return false;

        return true;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<std::string> words = Solution::splitWhiteSpaceandCollectWords("dog         cat cat dog");
    for (auto &word : words)
        std::cout << word << "\n";

    return 0;
}
