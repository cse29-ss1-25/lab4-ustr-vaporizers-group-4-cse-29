#ifndef LIST_H
#define LIST_H

#include <stdint.h>
#include <stdlib.h>
#include "ustr.h"

typedef struct List {
    int32_t size;         // Number of elements in the list
    int32_t capacity;     // Maximum number of elements the list can hold
    struct UStr* data;    // Pointer to the array holding the list elements
} List;

List new_list(int32_t initial_capacity);
List new_list_from_array(struct UStr* array, int32_t size);

// To implement
UStr join(List* list, UStr separator);
int8_t insert(List* list, UStr s, int32_t index);
int8_t listRemoveAt(List* list, int32_t index);
List split(UStr s, UStr separator);

#endif
