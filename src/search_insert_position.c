#include <limits.h>
#include <stdio.h>
#include "../lib/int_array.h"
#define MAX_LENGTH 10000

/**
 * Given a sorted array of distinct integers, determines the index of a given
 * value if it is found, or the index where it would be if it were inserted in
 * order.
 *
 * @param values a pointer to a sorted integer array
 * @param count the number of elements in the array
 * @param value the value to find
 * @return The index if the value is found; otherwise, the index where it
 *         would be if it were inserted in order.
 */
static int searchInsert(int *values, int count, int value)
{
    int result = int_array_binary_search(values, 0, count, value);

    if (result < value)
    {
        result = ~result;
    }

    return result;
}

int main()
{
    int value;
    int current;
    int previous = INT_MIN;
    int values[MAX_LENGTH];
    int count = 0;

    if (!scanf("%d", &value))
    {
        return 1;
    }

    while (scanf("%d", &current))
    {
        if (current <= previous || count == MAX_LENGTH)
        {
            break;
        }

        values[count] = current;
        previous = current;
        count++;
    }

    printf("@%d\n", searchInsert(values, count, value));

    return 0;
}
