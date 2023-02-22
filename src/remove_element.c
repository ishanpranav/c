#include <stdio.h>
#define MAX_LENGTH 100

/**
 * Given an integer array sorted in non-decreasing order, removes the
 * occurences of a given value in-place. The relative order of the elements may
 * be changed.
 *
 * @param values a pointer to an integer array
 * @param count the number of elements in the array
 * @return The number of meaningful elements in the array. The indices ranging
 *         from 0 (inclusive) to the return value (exclusive) contain the
 *         trimmed values. If the return value is zero, then the array is
 *         empty.
 */
static int removeElement(int *values, int count, int value)
{
    int result = 0;

    for (int i = 0; i < count; i++)
    {
        if (values[i] == value)
        {
            continue;
        }

        values[result] = values[i];
        result++;
    }

    return result;
}

int main()
{
    int value;
    int current;
    int values[MAX_LENGTH];
    int count = 0;

    scanf("%d", &value);

    while (scanf("%d", &current))
    {
        values[count] = current;
        count++;
    }

    count = removeElement(values, count, value);

    printf("[ ");

    for (int i = 0; i < count; i++)
    {
        printf("%d ", values[i]);
    }

    printf("]\n");

    return 0;
}
