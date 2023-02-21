#include <stdio.h>
#define MAX_LENGTH 15

/**
 * Converts a single-character Roman numeral to an integer.
 *
 * @param value the Roman numeral
 * @return The integral represetation of the Roman numeral.
 */
int numeralToInt(char value)
{
    switch (value)
    {
    case 'i':
    case 'I':
        return 1;

    case 'v':
    case 'V':
        return 5;

    case 'x':
    case 'X':
        return 10;

    case 'l':
    case 'L':
        return 50;

    case 'c':
    case 'C':
        return 100;

    case 'd':
    case 'D':
        return 500;

    case 'm':
    case 'M':
        return 1000;

    default:
        return 0;
    }
}

/**
 * Converts a string of Roman numerals to an integer.
 * @param value a pointer to a zero-terminated Roman numeral string
 * @return The integral representation of the Roman numeral string.
 */
int romanToInt(char *value)
{
    int result = 0;

    while (*value)
    {
        int numeral = numeralToInt(*value);

        value++;

        if (numeral < numeralToInt(*value))
        {
            result -= numeral;

            continue;
        }

        result += numeral;
    }

    return result;
}

int main()
{
    char buffer[MAX_LENGTH + 1];
    char *bufferReference = buffer;
    size_t capacity = MAX_LENGTH + 1;
    size_t count;

    do
    {
        count = getline(&bufferReference, &capacity, stdin);

        if (count > MAX_LENGTH)
        {
            return 1;
        }

        printf("%d\n", romanToInt(bufferReference));
    } while (count > 1);

    return 0;
}
