#include <vector>
#include <string>
#include <sstream>

class Solution
{
public:
    std::vector<std::string> split(std::string &s, char ch)
    {
        std::string token;
        std::vector<std::string> tokes;
        std::stringstream ss(s);
        while (std::getline(ss, token, ch))
            tokes.push_back(token);

        return tokes;
    }

    int mostWordsFound(std::vector<std::string> &sentences)
    {
        int mx = 0;
        for (auto &s : sentences)
        {
            auto parts = split(s, ' ');
            if (parts.size() > mx)
                mx = parts.size();
        }
        return mx;
    }
};