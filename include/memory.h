#ifndef CLOX_MEMORY_H
#define CLOX_MEMORY_H

#include "common.h"

#define GROW_CAPACITY(cap) \
    ((cap) < 8 ? 8 : cap * 2)

#define GROW_ARRAY(type, pointer, old_count, new_count) \
    (type *)reallocate(pointer,                         \
                       sizeof(type) * old_count,        \
                       sizeof(type) * new_count)

#define FREE_ARRAY(type, pointer, old_count) \
    (type *)reallocate(pointer, sizeof(type) * old_count, 0)

void *reallocate(void *pointer, size_t old_size, size_t new_size);

#endif