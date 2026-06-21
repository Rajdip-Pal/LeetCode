#include <iostream>
#include <vector>
#include <string>

class Solution {
    std::vector<std::string> wordsInSentence(const std::string& str) {
        std::vector<std::string> wordList;
        std::string tempWord = "";
        for (auto &&i : str) {
            if (i == ' ')
                wordList.push_back(tempWord), tempWord = "";
            else
                tempWord += i;          
        }
        wordList.push_back(tempWord);
        return wordList;
    }

    bool foo(std::vector<std::string> main_str, std::vector<std::string> aux_str) {
        int main_length = main_str.size(), aux_length = aux_str.size();

        while (main_length > 0 and aux_length > 0)
            if (main_str[0] == aux_str[0]) {
                main_str.erase(main_str.begin()); 
                aux_str.erase(aux_str.begin());
                main_length--, aux_length--;
            }
            else 
                break;

        while (main_length > 0 and aux_length > 0)
            if (main_str[main_length-1] == aux_str[aux_length-1]) {
                main_str.pop_back(), aux_str.pop_back();
                main_length--, aux_length--;
            }
            else 
                break;

        return main_length == 0;
    }

public:
    bool areSentencesSimilar(std::string& sentence1, std::string& sentence2) {
        if( sentence1.length() > sentence2.length() )
            return foo(wordsInSentence(sentence2), wordsInSentence(sentence1));
        else
            return foo(wordsInSentence(sentence1), wordsInSentence(sentence2));
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    std::string s1, s2;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);

    std::cout << std::boolalpha << s.areSentencesSimilar(s1,s2);
}
