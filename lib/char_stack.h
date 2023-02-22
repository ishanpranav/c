// https://learn.microsoft.com/en-us/dotnet/api/system.collections.generic.stack-1

#include <stdbool.h>

/**
 * Represents a variable size last-in-first-out (LIFO) collection of
 * characters.
 */
struct CharStack;

/**
 * Initializes a new instance of the stack class that is empty and has the
 * default initial capacity.
 *
 * @return A pointer to a new instance.
 */
struct CharStack *char_stack();

/**
 * Gets the number of characters contained in the stack.
 *
 * @param this a pointer to the current instance
 * @return The number of characters contained in the stack.
 */
int char_stack_count(struct CharStack *this);

/**
 * Ensures that the stack can hold up to a specified number of entries without
 * any further expansion of its backing storage.
 *
 * @param this a pointer to the current instance
 * @param capacity the minimum capacity to ensure
 * @return The new capacity of the stack.
 */
int char_stack_ensure_capacity(struct CharStack *this, int capacity);

/**
 * Inserts a character at the top of the stack.
 *
 * @param this a pointer to the current instance
 * @param item the character to push onto the stack.
 */
void char_stack_push(struct CharStack *this, char item);

/**
 * Returns a value that indicates whether there is a character at the top of
 * the stack, and if one is present, copies it to the result parameter, and
 * removes it from the stack.
 *
 * @param this a pointer to the current instance
 * @param result when this method returns, contains the value at the top of the
 *               stack, if present; otherwise, an undefined value. This
 *               parameter is passed uninitialized.
 * @return true if there is a character at the top of the stack; false if the
 *         stack is empty.
 */
bool char_stack_try_pop(struct CharStack *this, char *result);

/**
 * Allows the character stack to free resources and perform other cleanup
 * operations.
 *
 * @param this a pointer to the current instance
 */
void finalize_char_stack(struct CharStack *this);
