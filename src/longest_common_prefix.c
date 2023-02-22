#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 200

static int getLength(char **values, int count)
{
    int length = 0;
    int min = strlen(values[0]);

    for (int i = 1; i < count; i++)
    {
        int current = strlen(values[i]);

        if (current < min)
        {
            min = current;
        }
    }

    for (int j = 0; j <= min; j++)
    {
        for (int i = 0; i < count - 1; i++)
        {
            if (values[i][j] != values[i + 1][j])
            {
                return length;
            }

            if (i == count - 2)
            {
                length++;
            }
        }
    }

    return length;
}

/**
 * Gets the longest common prefix string amongst an array of strings.
 *
 * @param values a pointer to an array of pointers to zero-terminated strings
 * @param count the number of elements in the given array
 * @return The longest common prefix as a zero-terminated string.
 */
static char *longestCommonPrefix(char **values, int count)
{
    if (values == NULL || count == 0)
    {
        return "";
    }

    if (count == 1)
    {
        return values[0];
    }

    int length = getLength(values, count);

    if (length == 0)
    {
        return "";
    }

    char *result = malloc(sizeof(char) * (length + 1));

    result[length] = '\0';

    strncpy(result, values[0], length);

    return result;
}

int main()
{
    return 0;
}
