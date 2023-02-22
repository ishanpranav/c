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

struct IntLinkedList *int_linked_list()
{
    struct IntLinkedList *result = malloc(sizeof(struct IntLinkedList));

    result->head = NULL;
    result->tail = NULL;

    return result;
}

struct IntLinkedListNode *int_linked_list_first(struct IntLinkedList *this)
{
    return this->head;
}

struct IntLinkedListNode *int_linked_list_last(struct IntLinkedList *this)
{
    return this->tail;
}

void int_linked_list_add(struct IntLinkedList *this, int value)
{
    struct IntLinkedListNode *node = malloc(sizeof(struct IntLinkedListNode));

    node->item = value;
    node->next = NULL;

    int_linked_list_add_last(this, node);
}

void int_linked_list_add_last(
    struct IntLinkedList *this,
    struct IntLinkedListNode *node)
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

void int_linked_list_clear(struct IntLinkedList *this)
{
    while (this->head)
    {
        struct IntLinkedListNode *next = this->head;
        
        this->head = this->head->next;

        free(next);
    }

    this->tail = NULL;
}

void finalize_int_linked_list(struct IntLinkedList *this)
{
    int_linked_list_clear(this);
    free(this);
}

struct IntLinkedListNode *int_linked_list_node_next(
    struct IntLinkedListNode *this)
{
    return this->next;
}

int int_linked_list_node_value(struct IntLinkedListNode *this)
{
    return this->item;
}
