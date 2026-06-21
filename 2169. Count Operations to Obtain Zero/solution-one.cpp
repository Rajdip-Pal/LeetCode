class Solution
{
public:
    int countOperations(int num1, int num2)
    {
        int steps = 0;
        while (++steps && (0 != num1 && 0 != num2))
            num1 >= num2 ? num1 -= num2 : num2 -= num1;
        return steps - 1;
    }
};
