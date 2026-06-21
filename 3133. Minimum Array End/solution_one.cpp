class Solution
{
public:
    long long minEnd(int n, int x)
    {
        int i = 1;
        long long sum = x;
        while (i < n)
        {
            sum = x bitor (sum + 1);
            i++;
        }
        return sum;
    }
};

/*

[4,5,6]

4 -> 0100
5 -> 0101
6 -> 0110

0 -> 0000
1 -> 0001
2 -> 0010
3 -> 0011


[7,15]
 7 -> 00111
 8 -> 01000
15 -> 01111
17 -> 10001
23 -> 10111
*/
