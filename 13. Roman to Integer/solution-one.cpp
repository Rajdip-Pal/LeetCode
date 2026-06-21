#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
    const std::unordered_map<char, int> charValue = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

public:
    int romanToInt(std::string &str)
    {
        int totalValue{};
        char maxChar = 'I';

        while (!str.empty())
            if (charValue.at(str.back()) >= charValue.at(maxChar))
                totalValue += charValue.at(maxChar = str.back()), str.pop_back();
            else
                totalValue -= charValue.at(str.back()), str.pop_back();

        return totalValue;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
