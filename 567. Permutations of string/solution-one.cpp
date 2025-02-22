#include <iostream>
#include <unordered_map>

class Solution {
    bool checkMap(std::unordered_map<char, int>& map1,
                  std::unordered_map<char, int>& map2) {
        for (auto&& i : map1)
            if (map1[i.first] != map2[i.first])
                return false;
        return true;
    }

public:
    bool checkInclusion(std::string s1, std::string s2) {
        int length1 = s1.length(), length2 = s2.length();
        if (length1 <= length2) {
            std::unordered_map<char, int> map1, map2;
            for (auto&& i : s1)     map1[i]++;
            for (int i = 0; i < length1; i++)   map2[s2[i]]++;
            if (checkMap(map1, map2))   return true;
            for (int i = length1; i < length2; i++) {
                map2[s2[i - length1]]--;
                map2[s2[i]]++;
                if (checkMap(map1, map2))
                    return true;
            }
            return false;
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}