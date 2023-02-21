#include "system/boolean.h"
#include "system/console.h"
#include <stdio.h>

/**
 * Returns true if a given integer is a palindrome in decimal notation.
 * 
 * @param value the integer
 * @return 1 if the given integer is a palindrome; otherwise, 0.
*/
bool isPalindrome(int value)
{
    if (value < 0)
    {
        return false;
    }

    if (value == 0)
    {
        return true;
    }

    if (value % 10 == 0)
    {
        return false;
    }

    int reversed = 0;

    while (value > reversed)
    {
        reversed = (reversed * 10) + (value % 10);
        value /= 10;
    }

    return value == reversed || value == reversed / 10;
}

int main()
{
    int value;

    while (scanf("%d", &value))
    {
        printf("%s\n", btoa(isPalindrome(value)));
    }

    return 0;
}
