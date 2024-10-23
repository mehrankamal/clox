#include <stdio.h>

#include "memory.h"
#include "value.h"

void init_value_array(ValueArray *array)
{
    array->values = NULL;
    array->capacity = 0;
    array->count = 0;
}

void write_value_array(ValueArray *array, Value value)
{
    if (array->capacity < array->count + 1)
    {
        int old_capacity = array->capacity;
        array->capacity = GROW_CAPACITY(old_capacity);
        array->values = GROW_ARRAY(Value, array->values, old_capacity, array->capacity);
    }

    array->values[array->count] = value;
    array->count++;
}

void free_value_array(ValueArray *array)
{
    FREE_ARRAY(Value, array->values, array->count);
    init_value_array(array);
}

void print_value(Value value)
{
    switch (value.type)
    {
    case VAL_NUMBER:
        printf("%g", AS_NUMBER(value));
        break;
    case VAL_NIL:
        printf("nil");
        break;
    case VAL_BOOL:
        printf(AS_BOOL(value) ? "true" : "false");
        break;
    }
}