// https://learn.microsoft.com/en-us/dotnet/api/system.collections.generic.dictionary-2

#include <stdbool.h>

/**
 * Represents a collection of integer keys and integer values.
 */
struct IntDictionary;

/**
 * Initializes a new instance of the integer dictionary class that is empty and
 * has the default initial capacity, and uses the default equality comparer.
 *
 * @return A pointer to a new instance.
 */
struct IntDictionary *int_dictionary();

/**
 * Sets the value associated with the specified key.
 *
 * @param this a pointer to the current instance
 * @param key
 * @param value
 */
void int_dictionary_set(struct IntDictionary *this, int key, int value);

/**
 * Gets the number of key/value pairs contained in the integer dictionary.
 *
 * @param this a pointer to the current instance
 * @return The number of key/value pairs contained in the integer dictionary.
 */
int int_dictionary_count(struct IntDictionary *this);

/**
 * Ensures that the dictionary can hold up to a specified number of entries
 * without any further expansion of its backing storage.
 *
 * @param this a pointer to the current instance
 * @param capacity the minimum capacity to ensure
 * @return The new capacity of the dictionary.
 */
int int_dictionary_ensure_capacity(struct IntDictionary *this, int capacity);

/**
 * Attempts to add the specified key and value to the dictionary.
 *
 * @param this a pointer to the current instance
 * @param key the key of the element to add
 * @param value the value of the element to add
 * @return true if the key/value pair was added to the dictionary successfully;
 *         otherwise, false.
 */
bool int_dictionary_try_add(struct IntDictionary *this, int key, int value);

/**
 * Gets the value associated with the specified key.
 *
 * @param this a pointer to the current instance
 * @param key the key of the value to get
 * @param value when this method returns, contains the value associated with
 *              the specified key, if the key is found; otherwise, an undefined
 *              value. This parameter is passed uninitialized.
 * @return true if the integer contains an element with the specified key;
 *         otherwise, false.
 */
bool int_dictionary_try_get_value(struct IntDictionary *this, int key, int *value);

/**
 * Removes all keys and values from the integer dictionary.
 *
 * @param this a pointer to the current instance
 */
void int_dictionary_clear(struct IntDictionary *this);

/**
 * Allows the integer dictionary to free resources and perform other cleanup
 * operations.
 *
 * @param this a pointer to the current instance
 */
void finalize_int_dictionary(struct IntDictionary *this);
