#include <stdio.h>
#include "../lib/int_linked_list.h"

/**
 * Merges two linked lists sorted in non-decreasing order into one list sorted
 * in non-decreasing order. The list is created by splicing together the nodes
 * of the first two lists.
 * 
 * @param first a pointer to the first linked list
 * @param second a pointer to the second linked list
 * @return A pointer to linked list created by (destructively) splicing
 *         together the nodes of the first two linked lists.
 */
static struct IntLinkedList *mergeTwoSortedLists(
    struct IntLinkedList *first,
    struct IntLinkedList *second)
{
    struct IntLinkedList *result = int_linked_list();
    struct IntLinkedListNode *firstCurrent = int_linked_list_first(first);
    struct IntLinkedListNode *secondCurrent = int_linked_list_first(second);

    while (firstCurrent && secondCurrent)
    {
        if (int_linked_list_node_value(firstCurrent) < int_linked_list_node_value(secondCurrent))
        {
            int_linked_list_add_last(result, firstCurrent);

            firstCurrent = int_linked_list_node_next(firstCurrent);
        }
        else
        {
            int_linked_list_add_last(result, secondCurrent);

            secondCurrent = int_linked_list_node_next(secondCurrent);
        }
    }

    if (firstCurrent)
    {
        int_linked_list_add_last(result, firstCurrent);
    }

    if (secondCurrent)
    {
        int_linked_list_add_last(result, secondCurrent);
    }

    return result;
}

static struct IntLinkedList *getMerged()
{
    int current;
    int pass = 0;
    int previous = -1;
    struct IntLinkedList *first = int_linked_list();
    struct IntLinkedList *second = int_linked_list();

    while (scanf("%d", &current))
    {
        if (current < previous)
        {
            pass++;
        }

        switch (pass)
        {
        case 0:
            int_linked_list_add(first, current);
            break;

        case 1:
            int_linked_list_add(second, current);
            break;

        default:
            return mergeTwoSortedLists(first, second);
        }

        previous = current;
    }

    return mergeTwoSortedLists(first, second);
}

int main()
{
    struct IntLinkedList *merged = getMerged();

    printf("[ ");

    for (struct IntLinkedListNode *current = int_linked_list_first(merged);
         current != NULL;
         current = int_linked_list_node_next(current))
    {
        printf("%d ", int_linked_list_node_value(current));
    }

    printf("]\n");
    finalize_int_linked_list(merged);

    return 0;
}
