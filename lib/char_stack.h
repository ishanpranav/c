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
int char_stack_get_count(struct CharStack *this);

/**
 * Ensures that the capacity of this stack is at least the specified capacity.
 * If the current capacity is less than capacity, it is successively increased
 * to twice the current capacity until it is at least the specified capacity.
 *
 * @param this a pointer to the current instance
 * @param capacity the minimum capacity to ensure.
 * @return The new capacity of this stack.
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
 * @param result if present, the character at the top of the stack; otherwise,
 *               an undefined value.
 * @return true if there is a character at the top of the stack; false if the
 *         stack is empty.
 */
bool char_stack_try_pop(struct CharStack *this, char *result);

/**
 * Allows the character stack to free resources and perform other cleanup operations.
 *
 * @param this a pointer to the current instance
 */
void finalize_char_stack(struct CharStack *this);
