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

/**
 * @brief Add an item to an array at the given index
 *
 * This function adds an element to an array at a specific index.
 * The existing element and all elements following are shifted
 * to the right.
 *
 * @param arr The array to insert into
 * @param value The item to place in the array
 * @param index The place in the array to put the new item
 */
void array_insert(struct array *arr, int value, unsigned int index)
{
    if (index < 0 || index > arr->size) {
        return;
    }
    if (arr->capacity == arr->size) {
        array_resize(arr);
    }

    /* Shift items right */
    for (int i = arr->size; i > index; --i) {
        *(arr->data + i) = *(arr->data + i - 1);
    }
    *(arr->data + index) = value;
    ++arr->size;
}

/**
 * @brief Add an item to the beginning of an array
 *
 * @param arr The array to add an item to
 * @param value The item to add to the array
 */
void array_prepend(struct array *arr, int value)
{
    array_insert(arr, value, 0);
}

/**
 * @brief Remove the last element of an array and return it
 *
 * @param arr The array to remove an item from
 */
int array_pop(struct array *arr)
{
    if (arr->size <= 0) {
        exit(EXIT_FAILURE);
    }

    int value = *(arr->data + arr->size - 1);
    arr->size--;

    return value;
}

/**
 * @brief Remove an item from an array at a given index
 *
 * @param arr The array to remove an item from
 * @param index The index to remove an item from
 */
void array_delete(struct array *arr, unsigned int index)
{
    if (index < 0 || index > arr->size) {
        exit(EXIT_FAILURE);
    }

    for (int i = index; i < arr->size; ++i) {
        *(arr->data + i) = *(arr->data + i + 1);
    }
    --arr->size;
}

/**
 * @brief Remove an item from an array based on its value
 *
 * @param arr The array to remove an item from
 * @param value The item to remove
 */
void array_remove(struct array *arr, int value)
{
    int index;
    while ((index = array_find(arr, value)) != -1) {
        array_delete(arr, index);
    }
}

/**
 * @brief Find the index of an item in an array
 *
 * @param arr The array to search
 * @param value The item to find
 */
unsigned int array_find(struct array *arr, int value)
{
    int found = -1;
    for (int i = 0; i < arr->size; ++i) {
        if (array_at(arr, i) == value) {
            found = i;
            break;
        }
    }

    return found;
}
