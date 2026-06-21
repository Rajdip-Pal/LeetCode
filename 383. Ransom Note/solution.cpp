#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    bool canConstruct(std::string &ransomNote, std::string &magazine) {
        int ransome_note_length = ransomNote.length(), magazine_length = magazine.length();
        std::unordered_map<char, int> ransom_note_map, magazine_map;

        for (int i = 0; i < ransome_note_length; i++)
            ransom_note_map[ransomNote[i]]++;
        
        for (int i = 0; i < magazine_length; i++)
            magazine_map[magazine[i]]++;

        for (auto it = ransom_note_map.begin(); it != ransom_note_map.end(); it++) {
            if (magazine_map[it->first] < it->second) {
                return false;
            }
        }
        
        return true;
    }
};

auto init = [](){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    return 'c';
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
