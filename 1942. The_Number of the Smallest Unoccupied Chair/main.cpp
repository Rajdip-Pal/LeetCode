#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int smallestChair(const std::vector<std::vector<int>>& times, const int targetFriend) {

        int length = times.size();
        std::vector<std::pair<int, int>> intime, outtime;

        for (int i = 0; i < length; ++i) {
            intime.push_back({times[i].front(), i});
            outtime.push_back({times[i].back(), i});
        }

        std::sort(intime.begin(), intime.end());
        std::sort(outtime.begin(), outtime.end());

        std::unordered_map<int, int> occupied_chair;
        std::set<int> chairs;

        for (int i = 0; i < length; i++)
            chairs.insert(i);

        while (true) {
            if (intime.front().first < outtime.front().first) {
                occupied_chair[intime.front().second] = *chairs.begin();
                chairs.erase(chairs.begin());
                intime.erase(intime.begin());
            } else if (intime.front().first > outtime.front().first) {
                chairs.insert(occupied_chair[outtime.front().second]);
                occupied_chair.erase(outtime.front().second);
                outtime.erase(outtime.begin());
            } else {
                while (intime.front().first >= outtime.front().first) {
                    chairs.insert(occupied_chair[outtime.front().second]);
                    occupied_chair.erase(outtime.front().second);
                    outtime.erase(outtime.begin());   
                }
                occupied_chair[intime.front().second] = *chairs.begin();
                chairs.erase(chairs.begin());
                intime.erase(intime.begin());
            }
            if (occupied_chair.find(targetFriend) != occupied_chair.end())
                return occupied_chair[targetFriend];
        }
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
