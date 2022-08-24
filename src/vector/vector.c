/**
 * @file vector.c
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief A dynamically-resizing array implementation
 * @version 0.1
 * @date 2022-08-23
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

#include "./vector.h"

#include <stdlib.h>

/**
 * @brief Create a new, empty vector
 *
 * @param capacity The initial capacity of the vector

 * @return struct vector* Pointer to the dynamically-allocated vector structure
 */
struct vector *vector_init(unsigned int capacity)
{
    if (capacity <= 0) {
        return NULL;
    }

    struct vector *vec = (struct vector *)malloc(sizeof(struct vector));
    vec->size = 0;
    vec->capacity = capacity;

    vec->data = malloc(capacity * sizeof(int));
    if (!vec->data) {
        free(vec);
        return NULL;
    }

    return vec;
}

/**
 * @brief Free the memory used by a vector
 *
 * @param vector The vector to free
 */
void vector_free(struct vector *vector)
{
    if (vector && vector->data) {
        free(vector->data);
    }
    free(vector);
}

/**
 * @brief Double the capacity of a vector
 *
 * @param vector The vector to increase capacity for
 */
void vector_upsize(struct vector *vector)
{
    if (!vector) {
        return;
    }

    vector->capacity *= 2;
    vector->data = realloc(vector->data, sizeof(int) * vector->capacity);
}

/**
 * @brief Half the capacity of a vector
 *
 * @param vector The vector to decrease capacity for
 */
void vector_downsize(struct vector *vector)
{
    if (!vector || vector->capacity <= 1) {
        return;
    }

    vector->capacity /= 2;
    vector->data = realloc(vector->data, sizeof(int) * vector->capacity);
}

/**
 * @brief Get the current size of a vector
 *
 * @param vector The vector to check

 * @return unsigned int The current size of the vector
 */
unsigned int vector_size(struct vector *vector)
{
    return vector->size;
}

/**
 * @brief Get the current max capacity of a vector
 *
 * @param vector The vector to check

 * @return unsigned int The current max capacity of the vector
 */
unsigned int vector_capacity(struct vector *vector)
{
    return vector->capacity;
}

/**
 * @brief Check whether a vector is empty
 *
 * @param vector The vector to check

 * @return int 1 if the vector is empty, 0 otherwise
 */
int vector_is_empty(struct vector *vector)
{
    return vector->size == 0;
}

/**
 * @brief Fetch the item at a specific index
 *
 * @param vector The vector to fetch the item from
 * @param index The position in the vecotr to fetch

 * @return int The value of the item at the given index
 */
int vector_at(struct vector *vector, unsigned int index)
{
    if (index < 0 || index >= vector->size) {
        exit(EXIT_FAILURE);
    }

    return *(vector->data + index);
}

/**
 * @brief Add an item to the end of a vector
 *
 * @param vector The vector to add to
 * @param item The item to add
 */
void vector_push(struct vector *vector, int item)
{
    if (vector->size == vector->capacity) {
        /* Vector is full, so we double its capacity */
        vector_upsize(vector);
    }

    *(vector->data + vector->size++) = item;
}