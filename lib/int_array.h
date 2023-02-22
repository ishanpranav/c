// https://learn.microsoft.com/en-us/dotnet/api/system.array

/**
 * Searches a range of elements in a one-dimensional sorted array for an
 * integer.
 *
 * @param array The sorted one-dimensional array to search.
 * @param index The starting index of the range to search.
 * @param length The length of the range to search.
 * @param value The integer to search for.
 * @return The index of the specified value in the specified array, if the
 *         value is found; otherwise, a negative number. If the value is not
 *         found and the value is less than one or more elements in array, the
 *         negative number returned is the bitwise complement of the index of
 *         the first element that is larger than the value. If the value is not
 *         found and the value is greater than all elements in the array, the
 *         negative number returned is the bitwise complement of one more than
 *         the index of the last element. If this function is called with a
 *         non-sorted array, the return value can be incorrect and a negative
 *         number could be returned, even if value is present in the array.
 */
int int_array_binary_search(int *array, int index, int length, int value);
