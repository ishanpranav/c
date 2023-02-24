#include <stdio.h>
#include "../lib/int_dictionary.h"
#define MAX_LENGTH 10000

/**
 * Given an array of integers, returns indices of the two numbers that add up
 * to a given sum.
 *
 * @param values a pointer to an integer array
 * @param count the number of elements in the array
 * @param value the sum to achieve
 */
static void twoSum(int *values, int count, int sum, int *first, int *second)
{
    struct IntDictionary *dictionary = int_dictionary();

    for (int i = 0; i < count; i++)
    {
        int_dictionary_set(dictionary, values[i], i);
    }

    for (int i = 0; i < count; i++)
    {
        int j;

        if (!int_dictionary_try_get_value(dictionary, sum - values[i], &j))
        {
            continue;
        }

        if (i == j)
        {
            continue;
        }

        *first = i;
        *second = j;

        return;
    }

    finalize_int_dictionary(dictionary);
}

int main()
{
    int sum;
    int current;
    int values[MAX_LENGTH];
    int count = 1;

    if (!scanf("%d", &sum))
    {
        return 1;
    }

    if (!scanf("%d", &current))
    {
        return 1;
    }

    values[0] = current;

    while (scanf("%d", &current))
    {
        if (count == MAX_LENGTH)
        {
            break;
        }

        values[count] = current;
        count++;
    }

    printf("[ ");

    for (int i = 0; i < count; i++)
    {
        printf("%d ", values[i]);
    }

    printf("]\n");

    int first;
    int second;

    twoSum(values, count, sum, &first, &second);
    printf("@%d, @%d\n", first, second);

    return 0;
}
