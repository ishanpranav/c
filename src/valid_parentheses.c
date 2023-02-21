#include <stdio.h>
#include "../lib/char_stack.h"
#define MAX_LENGTH 10000

/**
 * Determines whether the opening and closing brackets in an input string are
 * valid. The input string must contain only the '(', ')', '[', ']', '{', and
 * '}' characters. An input string is valid if opening brackets are closed by
 * the same type of closing brackets, opening brackets are closed in the
 * correct order, and every closing bracket has a corresponding opening bracket
 * of the same type.
 *
 * @param value a pointer to a zero-terminated input string
 * @return true if the given string is valid; otherwise, false.
 */
bool isValid(char *value)
{
    if (value == NULL)
    {
        return false;
    }
    
    struct CharStack *stack = char_stack();

    while (*value)
    {
        switch (*value)
        {
        case '\n':
            break;

        case '(':
            char_stack_push(stack, ')');
            break;

        case '[':
            char_stack_push(stack, ']');
            break;

        case '{':
            char_stack_push(stack, '}');
            break;

        case ')':
        case ']':
        case '}':
            if (!char_stack_get_count(stack))
            {
                finalize_char_stack(stack);

                return false;
            }

            char result;

            if (!char_stack_try_pop(stack, &result) || result != *value)
            {
                finalize_char_stack(stack);

                return false;
            }
            break;

        default:
            finalize_char_stack(stack);

            return false;
        }

        value++;
    }

    int result = !char_stack_get_count(stack);

    finalize_char_stack(stack);

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

        if (isValid(bufferReference))
        {
            printf("valid\n");
        }
        else
        {
            printf("invalid\n");
        }
    } while (count > 1);

    return 0;
}
