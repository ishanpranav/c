// https://learn.microsoft.com/en-us/dotnet/api/system.int32

#include <stdbool.h>

/**
 * Compares this value to a specified signed integer and returns an
 * indication of their relative values.
 *
 * @param value the current value
 * @param other an integer to compare
 * @return A signed number indicating the relative values of this value and
 *         another given value. A return value less than 0 indicates that this
 *         value is less than the other value; a return value of 0 indicates
 *         that this value is equal to the other value; a return value greater
 *         than 1 indicates that this value is greater than the other value.
 */
inline int int_compare_to(int value, int other)
{
    return value - other;
}

/**
 * Returns a value indicating whether this value is equal to a specified
 * integer.
 *
 * @param value the current value
 * @param other an integer to compare
 * @return true if the other value has the same value as this value; otherwise,
 *         false.
 */
inline bool int_equals(int value, int other)
{
    return value == other;
}
