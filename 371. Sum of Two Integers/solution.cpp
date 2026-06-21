#include <iostream>

class Solution {
public:
    static int getSum(int& a, int& b) {
        int carry {};
        while (b != 0) {
            carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
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
