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

#include "array.h"

#include <stdlib.h>

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
 * @brief Update the capacity of an array
 *
 * This function will double the capacity of an array
 * if it is full, and cut it in half when it is not.
 *
 * @param arr The array to resize
 */
void array_resize(struct array *arr)
{
    if (arr->size == arr->capacity) {
        array_upsize(arr);
    }
    else {
        array_downsize(arr);
    }
}

/**
 * @brief Double the capacity of an array
 *
 * @param arr The array to upsize
 */
void array_upsize(struct array *arr)
{
    arr->capacity *= 2;
    arr->data = realloc(arr->data, sizeof(int) * arr->capacity);
}

/**
 * @brief Cut the capacity of an array in half
 *
 * @param arr The array to reduce capacity for
 */
void array_downsize(struct array *arr)
{
    if (arr->capacity <= 1) {
        return;
    }

    arr->capacity /= 2;
    arr->data = realloc(arr->data, sizeof(int) * arr->capacity);
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

/**
 * @brief Get the number of items an array can hold
 *
 * @param arr The array to check
 * @return unsigned int The number of items the array can hold
 */
unsigned int array_capacity(struct array *arr)
{
    return arr->capacity;
}

/**
 * @brief Determine whether an array is empty
 *
 * @param arr The array to test
 * @return int 1 if the array is empty, 0 otherwise
 */
int array_is_empty(struct array *arr)
{
    return arr->size == 0;
}

/**
 * @brief Get the item at a given index in an array
 *
 * @param arr The array to check
 * @param index The index of the array to fetch
 * @return int The item at the given index
 */
int array_at(struct array *arr, unsigned int index)
{
    if (index < 0 || index >= arr->size) {
        exit(EXIT_FAILURE);
    }
    return *(arr->data + index);
}

/**
 * @brief Add an item to the end of an array
 *
 * @param arr The array to add an item to
 * @param value The item to add to the array
 */
void array_push(struct array *arr, int value)
{
    if (arr->size == arr->capacity) {
        array_upsize(arr);
    }

    *(arr->data + arr->size++) = value;
}
