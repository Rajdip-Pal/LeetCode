class Solution
{
public:
    /**
     * @param num given the number to check;
     * @return bool type if true or false;
     */
    bool isPerfectSquare(const int &num)
    {
        long long i{1}, tempSquare{};
        while ((tempSquare = i * i) <= num)
            if (tempSquare == num)
                return i;
            else
                i++;

        return false;
    }
};
