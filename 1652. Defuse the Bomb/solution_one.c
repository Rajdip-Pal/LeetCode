#include <stdio.h>
#include <stdlib.h>

void init()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
}

int *decrypt(int *code, int codeSize, int k, int *returnSize)
{
    init();

    int size = codeSize + abs(k) + 1, sum = 0, i, j;
    int __temp[size];
    int start, end;

    int *result = (int *)malloc(codeSize * sizeof(int));

    if (k >= 0)
        for (i = 0; i < size; i++)
            __temp[i] = code[i % codeSize];
    else
    {
        k = abs(k);
        for (i = size - 1, j = codeSize - 1; j >= 0; i--, j--)
            __temp[i] = code[j];
        for (j = codeSize - 1; i >= 0; j--, i--)
            __temp[i] = code[j];
    }

    start = 1, end = k;
    for (i = start; i <= end; i++)
        sum += __temp[i];
    for (i = 0; i < codeSize; i++)
        result[i] = sum, sum += __temp[i + k + 1] - __temp[i + 1];

    *returnSize = codeSize;
    return result;
}

int main()
{
    int code[] = {2, 4, 9, 3};
    int codeSize = sizeof(code) / sizeof(code[0]);
    int k = -2;
    int *result;

    result = decrypt(code, codeSize, k, result);

    return 0;
}
