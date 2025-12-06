#include <vector>

class Solution
{
public:
    bool isOneBitCharacter(std::vector<int> &bits)
    {
        bool flag = false;
        for (int i = 0; i < bits.size();)
            if (bits[i] == 1)
                i += 2,
                    flag = false;
            else
                i += 1,
                    flag = true;
        return flag;
    }
};
