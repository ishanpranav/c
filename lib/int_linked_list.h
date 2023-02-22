/**
 * Represents a singly linked list.
 */
struct IntLinkedList;

/**
 * Represents a node in an integer linked list.
 */
struct IntLinkedListNode;

/**
 * Initializes a new instance of the integer linked list data structure that is
 * empty.
 *
 * @return A pointer to a new instance.
 */
struct IntLinkedList *int_linked_list();

/**
 * Gets the first node of the integer linked list.
 *
 * @param this a pointer to the current instance
 * @return A pointer to the first node of the integer linked list.
 */
struct IntLinkedListNode *int_linked_list_first(struct IntLinkedList *this);

/**
 * Gets the last node of the integer linked list.
 *
 * @param this a pointer to the current instance
 * @return A pointer to the last node of the integer linked list.
 */
struct IntLinkedListNode *int_linked_list_last(struct IntLinkedList *this);

/**
 * Adds a new node containing the specified integer at the end of the linked
 * list.
 *
 * @param this a pointer to the current instance
 * @param value the integer to add at the end of the linked list.
 */
void int_linked_list_add(struct IntLinkedList *this, int value);

/**
 * Adds the specified new node at the end of the integer linked list.
 *
 * @param this a pointer to the current instance
 * @param node a pointer to the new node to add at the end of the integer
 *             linked list.
 */
void int_linked_list_add_last(
    struct IntLinkedList *this,
    struct IntLinkedListNode *node);

/**
 * Removes all nodes from the integer linked list.
 *
 * @param this a pointer to the current instance
 */
void int_linked_list_clear(struct IntLinkedList *this);

/**
 * Allows the integer linked list to free resources and perform other cleanup
 * operations.
 *
 * @param this a pointer to the current instance
 */
void finalize_int_linked_list(struct IntLinkedList *this);

/**
 * Gets the next node in the integer linked list.
 *
 * @param this a pointer to the current instance
 * @return A pointer to the next node in the integer linked list, or NULL if
 *         the current node is the last node in the linked list.
 */
struct IntLinkedListNode *int_linked_list_node_next(
    struct IntLinkedListNode *this);

/**
 * Gets the integer contained in the node.
 *
 * @param this a pointer to the current instance
 * @return The integer contained in the node.
 */
int int_linked_list_node_value(struct IntLinkedListNode *this);
