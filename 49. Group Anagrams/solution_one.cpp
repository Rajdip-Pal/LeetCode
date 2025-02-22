#include <string>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string> &strs)
    {
        int index;
        std::vector<uint8_t> frequency;
        std::vector<std::vector<std::string>> result;
        std::vector<std::vector<uint8_t>> frequency_holder;

        auto frequency_creator = [](const std::string &s) -> std::vector<uint8_t>
        {
            std::vector<uint8_t> result(26);
            for (char c : s)
                result[c - 'a']++;
            return result;
        };

        for (int i = 0; i < strs.size(); i++)
        {
            index = -1;

            frequency = frequency_creator(strs[i]);
            for (int j = 0; j < frequency_holder.size(); j++)
            {
                if (frequency == frequency_holder.at(j))
                {
                    index = j;
                    break;
                }
            }

            if (index != -1)
                result.at(index).push_back(strs[i]);
            else
                result.push_back({strs[i]}),
                    frequency_holder.push_back(frequency);
        }
        return result;
    }
};
