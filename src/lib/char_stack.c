#include <math.h>
#include <stdlib.h>
#include "char_stack.h"
#define DEFAULT_CAPACITY 4

struct CharStack
{
    int count;
    int capacity;
    char *array;
};

struct CharStack *char_stack()
{
    struct CharStack *instance = malloc(sizeof(struct CharStack));

    instance->count = 0;
    instance->capacity = 0;
    instance->array = NULL;

    return instance;
}

int char_stack_get_count(struct CharStack *this)
{
    return this->count;
}

void grow(struct CharStack *this, int min)
{
    this->capacity *= 2;

    if (min > this->capacity)
    {
        this->capacity = min;
    }

    if (DEFAULT_CAPACITY > this->capacity)
    {
        this->capacity = DEFAULT_CAPACITY;
    }

    if (this->array == NULL)
    {
        this->array = malloc(sizeof(char) * this->capacity);
    }
    else
    {
        this->array = realloc(this->array, sizeof(char) * this->capacity);
    }
}

int char_stack_ensure_capacity(struct CharStack *this, int capacity)
{
    if (this->capacity < capacity)
    {
        grow(this, capacity);
    }

    return this->capacity;
}

void char_stack_push(struct CharStack *this, char item)
{
    if (this->count == this->capacity)
    {
        grow(this, this->count + 1);
    }

    this->array[this->count] = item;
    this->count++;
}

bool char_stack_try_pop(struct CharStack *this, char *result)
{
    if (!this->count)
    {
        return false;
    }

    this->count--;

    *result = this->array[this->count];

    return true;
}

void finalize_char_stack(struct CharStack *this)
{
    free(this->array);
    free(this);
}
