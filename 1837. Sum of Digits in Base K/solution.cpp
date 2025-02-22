#include <iostream>

/**
 * Solution 1837. Sum of Digits in Base K
 *
 * @Start
 */

class Solution
{
    static void convertNumber(const int &realNumber, const int &base, int &result)
    {
        if (!realNumber)
            return;
        else
        {
            result += realNumber % base;
            convertNumber(realNumber / base, base, result);
        }
    }

public:
    int sumBase(const int &number, const int &base)
    {
        int result{};
        convertNumber(number, base, result);
        return result;
    }
};

/**
 * @End
 */

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
