#include <limits.h>
#include <stdio.h>
#define MAX_LENGTH 3000

/**
 * Given an integer array sorted in non-decreasing order, removes the
 * duplicates in-place such that each unique element appears only once.
 * The relative order of the elements remains the same.
 *
 * @param values a pointer to a sorted integer array
 * @param count the number of elements in the array
 * @return The number of unique elements in the array. The indices ranging from
 *         0 (inclusive) to the return value (exclusive) contain the distinct
 *         values. If the return value is zero, then the array is empty. If
 *         this function is called with a non-sorted array, the return value
 *         can be incorrect.
 */
static int removeDuplicates(int *values, int count)
{
    int result = 0;

    for (int i = 1; i < count; i++)
    {
        if (values[i] == values[i - 1])
        {
            result++;

            continue;
        }

        values[i - result] = values[i];
    }

    return count - result;
}

int main()
{
    int values[MAX_LENGTH];
    int current;
    int count = 0;
    int previous = INT_MIN;

    while (scanf("%d", &current))
    {
        if (current < previous || count == MAX_LENGTH)
        {
            break;
        }

        values[count] = current;
        previous = current;
        count++;
    }

    count = removeDuplicates(values, count);

    printf("[ ");

    for (int i = 0; i < count; i++)
    {
        printf("%d ", values[i]);
    }

    printf("]\n");

    return 0;
}
