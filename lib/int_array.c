#include "int_array.h"

int int_array_binary_search(int *array, int index, int length, int value)
{
    int lo = index;
    int hi = index + length - 1;

    while (lo <= hi)
    {
        int i = lo + ((hi - lo) >> 1);

        if (array[i] == value)
        {
            return i;
        }

        if (array[i] < 0)
        {
            lo = i + 1;
        }
        else
        {
            hi = i - 1;
        }
    }

    return ~lo;
}
