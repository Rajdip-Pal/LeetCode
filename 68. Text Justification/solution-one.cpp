#include <vector>
#include <string>

class Solution
{
public:
    std::vector<std::string> fullJustify(const std::vector<std::string> &words, const int &maxWidth)
    {
        int width{}, wordLength{};
        int start_word{}, end_word{};
        int spaces{}, extra_spaces{};
        std::string produceOutput;
        std::vector<std::string> result;

        for (int i = 0; i < words.size();)
        {
            end_word = start_word = i;
            wordLength = width = words.at(i).length();
            produceOutput = words[i++], start_word++;

            while ((i < words.size()) and (width + 1 + words.at(i).length() <= maxWidth))
            {
                width += 1 + words.at(i).length();
                wordLength += words.at(i).length();
                end_word = i++;
            }

            if (i < words.size())
            {
                if (end_word < start_word)
                {
                    spaces = (maxWidth - wordLength),
                    extra_spaces = 0;
                    for (int j = 0; j < spaces; j++)
                        produceOutput += " ";
                }
                else
                {
                    spaces = ((maxWidth - wordLength) / (end_word - start_word + 1)),
                    extra_spaces = ((maxWidth - width) % (end_word - start_word + 1));

                    while (start_word <= end_word)
                    {
                        for (int j = 0; j < spaces; j++)
                            produceOutput += " ";
                        if (extra_spaces != 0)
                            produceOutput += " ", extra_spaces--;
                        produceOutput += words[start_word++];
                    }
                }
            }
            else
            {
                while (start_word <= end_word)
                {
                    produceOutput += " ";
                    produceOutput += words[start_word++];
                }

                extra_spaces = maxWidth - produceOutput.length();
                for (int j = 0; j < extra_spaces; j++)
                    produceOutput += " ";
            }

            spaces = extra_spaces = 0;
            result.push_back(produceOutput);
            produceOutput.clear();
        }

        return result;
    }
};
