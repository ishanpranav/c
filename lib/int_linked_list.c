// https://github.com/dotnet/runtime/blob/main/src/libraries/System.Collections/src/System/Collections/Generic/LinkedList.cs

#include <stdlib.h>
#include "int_linked_list.h"

struct IntLinkedList
{
    struct IntLinkedListNode *head;
    struct IntLinkedListNode *tail;
};

struct IntLinkedListNode
{
    int item;
    struct IntLinkedListNode *next;
};

IntLinkedList int_linked_list()
{
    IntLinkedList instance = malloc(sizeof *instance);

    instance->head = NULL;
    instance->tail = NULL;

    return instance;
}

IntLinkedListNode int_linked_list_first(IntLinkedList this)
{
    return this->head;
}

IntLinkedListNode int_linked_list_last(IntLinkedList this)
{
    return this->tail;
}

void int_linked_list_add(IntLinkedList this, int value)
{
    IntLinkedListNode node = malloc(sizeof *node);

    node->item = value;
    node->next = NULL;

    int_linked_list_add_last(this, node);
}

void int_linked_list_add_last(IntLinkedList this, IntLinkedListNode node)
{
    if (this->head == NULL)
    {
        this->head = node;
        this->tail = node;

        return;
    }

    this->tail->next = node;
    this->tail = node;
}

void int_linked_list_clear(IntLinkedList this)
{
    while (this->head)
    {
        IntLinkedListNode next = this->head;

        this->head = this->head->next;

        free(next);
    }

    this->tail = NULL;
}

void finalize_int_linked_list(IntLinkedList this)
{
    int_linked_list_clear(this);
    free(this);
}

IntLinkedListNode int_linked_list_node_next(IntLinkedListNode this)
{
    return this->next;
}

int int_linked_list_node_value(IntLinkedListNode this)
{
    return this->item;
}
