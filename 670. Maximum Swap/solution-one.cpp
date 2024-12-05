#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
    template <typename type>
    static void swap_value(type& num1, type& num2) {
        type temp = num1;
        num1 = num2;
        num2 = temp;
    }

public:
    static int maximumSwap(const int &number)
    {
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);

        int result_number = number;
        bool willContinue = true;
        std::pair<unsigned short, unsigned short> temp_digit;
        std::vector<unsigned short> digits;

        while (result_number)
            digits.push_back(result_number % 10), result_number /= 10;
        std::reverse(digits.begin(), digits.end());

        short i{}, j{};
        while (willContinue && i < digits.size() - 1)
        {
            j = i + 1;
            temp_digit = {digits[i], i};
            while (willContinue && j < digits.size())
            {
                if (digits[j] >= temp_digit.first)
                    temp_digit.first = digits[j], temp_digit.second = j;
                j++;
            }

            if (temp_digit.first > digits[i]) {
                swap_value<unsigned short>(digits[i], digits[temp_digit.second]);
                willContinue = false;
            }
            i++;
        }

        for (int i = 0; i < digits.size(); i++)
            result_number = (result_number * 10) + digits[i];

        return result_number;
    }
};

int main(int argc, char const *argv[])
{
    int number = 1993;
    std::cout << Solution::maximumSwap(number) << std::endl;
    return 0;
}
