// https://learn.microsoft.com/en-us/dotnet/api/system.collections.generic.linkedlist-1
// https://learn.microsoft.com/en-us/dotnet/api/system.collections.generic.linkedlistnode-1

/**
 * Represents a singly linked list.
 */
struct IntLinkedList;

/**
 * Represents a node in an integer linked list.
 */
struct IntLinkedListNode;

/**
 * Represents a singly linked list.
 */
typedef struct IntLinkedList *IntLinkedList;

/**
 * Represents a node in an integer linked list.
 */
typedef struct IntLinkedListNode *IntLinkedListNode;

/**
 * Initializes a new instance of the integer linked list data structure that is
 * empty.
 *
 * @return A new instance.
 */
IntLinkedList int_linked_list();

/**
 * Gets the first node of the integer linked list.
 *
 * @param this the current instance
 * @return The first node of the integer linked list.
 */
IntLinkedListNode int_linked_list_first(IntLinkedList this);

/**
 * Gets the last node of the integer linked list.
 *
 * @param this the current instance
 * @return The last node of the integer linked list.
 */
IntLinkedListNode int_linked_list_last(IntLinkedList this);

/**
 * Adds a new node containing the specified integer at the end of the linked
 * list.
 *
 * @param this the current instance
 * @param value the integer to add at the end of the linked list.
 */
void int_linked_list_add(IntLinkedList this, int value);

/**
 * Adds the specified new node at the end of the integer linked list.
 *
 * @param this the current instance
 * @param node The new node to add at the end of the integer linked list.
 */
void int_linked_list_add_last(IntLinkedList this, IntLinkedListNode node);

/**
 * Removes all nodes from the integer linked list.
 *
 * @param this the current instance
 */
void int_linked_list_clear(IntLinkedList this);

/**
 * Allows the integer linked list to free resources and perform other cleanup
 * operations.
 *
 * @param this the current instance
 */
void finalize_int_linked_list(IntLinkedList this);

/**
 * Gets the next node in the integer linked list.
 *
 * @param this the current instance
 * @return The next node in the integer linked list, or NULL if the current
 *         node is the last node in the linked list.
 */
IntLinkedListNode int_linked_list_node_next(IntLinkedListNode this);

/**
 * Gets the integer contained in the node.
 *
 * @param this the current instance
 * @return The integer contained in the node.
 */
int int_linked_list_node_value(IntLinkedListNode this);
