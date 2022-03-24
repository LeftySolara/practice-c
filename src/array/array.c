/**
 * @file array.c
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief A mutable, dynamically-resizing array implementation
 * @version 0.1
 * @date 2022-03-23
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

#include <stdlib.h>

#include "array.h"

/**
 * @brief Create a new, empty array with the given capacity
 *
 * @param capacity The initial capacity of the array
 *
 * @return struct array* Pointer to a dynamically-allocated array structure, or NULL on error
 */
struct array *array_new(unsigned int capacity)
{
    if (capacity <= 0) {
        return NULL;
    }

    struct array *arr = (struct array *)malloc(sizeof(struct array));
    if (!arr) {
        return NULL;
    }

    arr->size = 0;
    arr->capacity = capacity;

    arr->data = malloc(capacity * sizeof(int));
    if (!arr->data) {
        free(arr);
        return NULL;
    }

    return arr;
}

/**
 * @brief Free all memory used by an array
 *
 * @param arr The array to free
 */
void array_free(struct array *arr)
{
    if (arr && arr->data) {
        free(arr->data);
    }
    free(arr);
}

/**
 * @brief Get the number of items in an array
 *
 * @param arr The array to check
 * @return unsigned int The number of items in the array
 */
unsigned int array_size(struct array *arr)
{
    return arr->size;
}
