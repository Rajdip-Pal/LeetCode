#include <string>

class Solution
{
public:
    bool canChange(std::string &start, const std::string &target)
    {
        char ch;
        int length = start.length();
        int start_ptr{}, target_ptr{};

        int countL[2] = {0, 0}, countR[2] = {0, 0};

        for (int i = 0; i < length; i++)
        {
            if (start[i] == 'L')
                countL[0]++;
            if (start[i] == 'R')
                countR[0]++;
            if (target[i] == 'L')
                countL[1]++;
            if (target[i] == 'R')
                countR[1]++;
        }

        if (countL[0] != countL[1] or countR[0] != countR[1])
            return false;

        while (start_ptr < length and target_ptr < length)
        {
            while (target_ptr < length and target[target_ptr] != 'L')
                target_ptr++;

            if (target_ptr < length)
            {
                while (start_ptr < target_ptr)
                    if (start[start_ptr] == 'L')
                        return false;
                    else
                        ++start_ptr;

                if (start[start_ptr] == target[target_ptr])
                {
                    ch = start[target_ptr];
                    start[target_ptr] = start[start_ptr];
                    start[start_ptr] = ch;
                    ++start_ptr, ++target_ptr;
                }
                else if (start[start_ptr] == 'R')
                    return false;
                else
                    ++start_ptr;
            }
        }

        start_ptr = target_ptr = length - 1;
        while (start_ptr >= 0 and target_ptr >= 0)
        {
            while (target_ptr >= 0 and target[target_ptr] != 'R')
                target_ptr--;

            if (target_ptr >= 0)
            {
                while (start_ptr > target_ptr)
                    if (start[start_ptr] == 'R')
                        return false;
                    else
                        --start_ptr;

                if (start[start_ptr] == target[target_ptr])
                    --start_ptr, --target_ptr;
                else if (start[start_ptr] == 'L')
                    return false;
                else
                    --start_ptr;
            }
        }

        return true;
    }
};
