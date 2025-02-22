#include <iostream>
#include <string>

class Solution {
public:
    static std::string longestDiverseString(int a, int b, int c) {
        std::ios::sync_with_stdio(0);
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);

        int length{};
        std::string happy_string;
        std::pair<int, char> last_character;

        while (a >= 2 && b >= 2 && c >= 2) {
            happy_string.append("aabbcc");
            a -= 2, b -= 2, c -= 2;
        }

        while (a > 0 && b > 0 && c > 0) {
            if (a - 2 >= 0)
                happy_string.append("aa"), a -= 2;
            else
                happy_string.append("a"), a -= 1;

            if (b - 2 >= 0)
                happy_string.append("bb"), b -= 2;
            else
                happy_string.append("b"), b -= 1;

            if (c - 2 >= 0)
                happy_string.append("cc"), c -= 2;
            else
                happy_string.append("c"), c -= 1;
        }

        while ((a > 0 && b > 0) || (b > 0 && c > 0) || (a > 0 && c > 0)) {
            if (a >= 2)
                happy_string.append("aa"), a -= 2;
            else if (a >= 1)
                happy_string.append("a"), a -= 1;

            if (b >= 2)
                happy_string.append("bb"), b -= 2;
            else if (b >= 1)
                happy_string.append("b"), b -= 1;

            if (c >= 2)
                happy_string.append("cc"), c -= 2;
            else if (c >= 1)
                happy_string.append("c"), c -= 1;
        }

        if (a)
            last_character = {a, 'a'};
        else if (b)
            last_character = {b, 'b'};
        else if (c)
            last_character = {c, 'c'};
        else
            return happy_string;

        if (happy_string[0] != last_character.second)
            if (last_character.first >= 2) {
                happy_string.insert(happy_string.begin(),
                                    last_character.second);
                happy_string.insert(happy_string.begin(),
                                    last_character.second);
                last_character.first -= 2;
            } else {
                happy_string.insert(happy_string.begin(),
                                    last_character.second);
                last_character.first--;
            }

        length = happy_string.length();

        for (int i = 2; (i < length) && (last_character.first > 0); i++) {
            if ((happy_string[i] != last_character.second) &&
                (happy_string[i - 1] != last_character.second)) {
                if (last_character.first >= 2) {
                    happy_string.insert(happy_string.begin() + i,
                                        last_character.second);
                    happy_string.insert(happy_string.begin() + i,
                                        last_character.second);
                    i += 2;
                    length += 2;
                    last_character.first -= 2;
                } else {
                    happy_string.insert(happy_string.begin() + i,
                                        last_character.second);
                    i++;
                    length++;
                    last_character.first--;
                }
            }
        }

        if (happy_string[length - 1] != last_character.second)
            if (last_character.first >= 2) {
                happy_string.insert(happy_string.end(), last_character.second);
                happy_string.insert(happy_string.end(), last_character.second);
                last_character.first -= 2;
            } else if (last_character.first > 0) {
                happy_string.insert(happy_string.end(), last_character.second);
                last_character.first--;
            }

        return happy_string;
    }
};

int main(int argc, char const *argv[])
{
    Solution::longestDiverseString(7, 1, 0);
    std::string str = "bbabbabbcbbcbbabcbbcbbcbbcbbcbb";

    std::cout << str.length();
    return 0;
}
