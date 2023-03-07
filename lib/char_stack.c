// https://github.com/dotnet/runtime/blob/main/src/libraries/System.Collections/src/System/Collections/Generic/Stack.cs

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

CharStack char_stack()
{
    CharStack instance = malloc(sizeof *instance);

    instance->count = 0;
    instance->capacity = 0;
    instance->array = NULL;

    return instance;
}

int char_stack_count(CharStack this)
{
    return this->count;
}

static void grow(CharStack this, int min)
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
        this->array = malloc(sizeof *this->array * this->capacity);
    }
    else
    {
        this->array = realloc(this->array, sizeof *this->array * this->capacity);
    }
}

int char_stack_ensure_capacity(CharStack this, int capacity)
{
    if (this->capacity >= capacity)
    {
        return this->capacity;
    }

    grow(this, capacity);

    return this->capacity;
}

void char_stack_push(CharStack this, char item)
{
    if (this->count == this->capacity)
    {
        grow(this, this->count + 1);
    }

    this->array[this->count] = item;
    this->count++;
}

bool char_stack_try_pop(CharStack this, char *result)
{
    if (!this->count)
    {
        return false;
    }

    this->count--;

    *result = this->array[this->count];

    return true;
}

void finalize_char_stack(CharStack this)
{
    free(this->array);
    free(this);
}
