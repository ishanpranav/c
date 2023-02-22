#include <stdbool.h>
#include <stdio.h>

/**
 * Determines whether a given integer is a palindrome in decimal notation.
 * 
 * @param value the integer
 * @return true if the given integer is a palindrome; otherwise, false.
*/
static bool isPalindrome(int value)
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
        if (isPalindrome(value))
        {
            printf("palindrome\n");
        }
        else
        {
            printf("non-palindrome\n");
        }
    }

    return 0;
}
