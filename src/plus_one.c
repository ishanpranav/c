#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 100

/**
 * Given a large integer represented as an integer array of digits, increments
 * the large integer by one and returns the resulting array of digits. Memory
 * is only allocated if the length has changed. 
 *
 * @param digits an pointer to an integer array of digits, ordered from
 *               most significant to least significant in left-to-right order.
 *               The large integer does not contain any leading zeroes.
 * @param length the number of digits in the large integer
 * @return The array of digits that results from incrementing the given large
 *         integer by one.
 */
static int *plusOne(int *digits, int *length)
{
    for (int i = *length - 1; i >= 0; i--)
    {
        if (digits[i] < 9)
        {
            digits[i]++;

            return digits;
        }

        digits[i] = 0;
    }

    (*length)++;
    digits = calloc(*length, sizeof *digits);
    digits[0] = 1;

    return digits;
}

int main()
{
    int current;
    int values[MAX_LENGTH];
    int count = 0;
    bool significant = false;

    while (scanf("%d", &current))
    {
        if (count == MAX_LENGTH)
        {
            break;
        }

        if (!significant)
        {
            if (current)
            {
                significant = true;
            }
            else
            {
                continue;
            }
        }

        values[count] = current;
        count++;
    }

    int oldCount = count;
    int *digits = plusOne(values, &count);

    printf("[ ");

    for (int i = 0; i < count; i++)
    {
        printf("%d ", digits[i]);
    }

    printf("]\n");

    if (count != oldCount)
    {
        free(digits);
    }
    
    return 0;
}
