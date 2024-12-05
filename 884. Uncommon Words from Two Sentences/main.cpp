#include <bits/stdc++.h>

class Solution {
private:
    void updateWordList(const std::string &s, std::vector<std::pair<std::string,int>> &wordList)
    {
        std::string word;
        int length = s.length();
        for (auto i : s)
        {
            if (i != ' ')
            {
                word.push_back(i);
                continue;
            }

            for (std::pair<std::string, int>& i : wordList)
                if ( i.first == word )
                    (i.second)++, word = "";
            
            if (word == "") continue;
            wordList.push_back({word,1});
            word = "";
        }     
    }

    std::vector<std::string> uncommonList(const std::vector<std::pair<std::string,int>> &wordList)
    {
        std::vector<std::string> list;
        for ( std::pair<std::string,int> i : wordList)
        {
            if (i.second == 1)
                list.push_back(i.first);
        }
        return list;
    }
public:
    std::vector<std::string> uncommonFromSentences(std::string &s1, std::string &s2) {
        std::vector<std::pair<std::string,int>> wordList;
        updateWordList(s1,wordList);
        updateWordList(s2,wordList);

        for (auto i : wordList)
            std::cout << i.first << " " << i.second << std::endl;
        std::cout << std::endl;

        return uncommonList(wordList);
    }
};

int main(int argc, char const *argv[])
{
    Solution obj;
    std::string s1 = "this apple is sweet ";
    std::string s2 = "this apple is sour ";

    std::vector<std::string> list = obj.uncommonFromSentences(s1,s2);

    for (auto i : list)
        std::cout << i << std::endl;
    

    return 0;
}
