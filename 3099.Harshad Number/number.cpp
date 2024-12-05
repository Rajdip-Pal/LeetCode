#include <iostream>

int number(const int element)
{
    int temp{element}, auxider{};
    while (temp)
    {
        auxider += temp % 10;
        temp = temp / 10;
    }
    if (element % auxider)
        return -1;
    return auxider;
}

int main()
{
    int x;
    std::cin >> x;
    std::cout << number(x);
    return 0;
}
