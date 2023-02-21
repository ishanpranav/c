#include "lib/boolean.h"
#include <stdio.h>

/**
 * Returns true if a given integer is a palindrome in decimal notation.
 * 
 * @param x the integer
 * @return 1 if the given integer is a palindrome; otherwise, 0.
*/
bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }

    if (x == 0)
    {
        return true;
    }

    if (x % 10 == 0)
    {
        return false;
    }

    int reversed = 0;

    while (x > reversed)
    {
        reversed = (reversed * 10) + (x % 10);
        x /= 10;
    }

    return x == reversed || x == reversed / 10;
}

/**
 * The main entry point for the application.
 * 
 * @return An exit code. This value is always 0, indicating success.
 */
int main()
{
    int x;

    while (scanf("%d", &x))
    {
        printf("%s\n", btoa(isPalindrome(x)));
    }

    return 0;
}
