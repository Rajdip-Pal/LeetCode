#include <iostream>

/**
 * Solution 1837. Sum of Digits in Base K
 *
 * @Start
 */

class Solution
{
    static int convertNumber(const int &realNumber, const int &base)
    {
        if (!realNumber)
            return realNumber;
        else
            return convertNumber(realNumber / base, base) * 10 + realNumber % base;
    }

public:
    int sumBase(const int &number, const int &base)
    {
        int result{};
        int newNumber = convertNumber(number, base);
        while (newNumber)
        {
            result += newNumber % 10;
            newNumber /= 10;
        }

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
