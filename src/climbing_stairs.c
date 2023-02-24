#include <stdio.h>

/**
 * Gets the n-th number in a Fibonacci-like sequence.
 * 
 * @param n the one-based position in the sequence to compute
 * @return the element of the sequence
*/
int climbStairs(int n)
{
    if (n <= 2)
    {
        return n;
    }

    int result;
    int first = 1;
    int second = 2;

    for (int i = 3; i <= n; i++)
    {
        result = second + first;
        first = second;
        second = result;
    }

    return result;
}

int main()
{
    int value;

    while (scanf("%d", &value))
    {
        printf("%d\n", climbStairs(value));
    }

    return 0;
}
