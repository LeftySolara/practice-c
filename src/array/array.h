/**
 * @file array.h
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief A mutable, dynamically-resizing array implementation
 * @version 0.1
 * @date 2022-03-23
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

/**
 * @brief A dynamically-resizing array
 */
struct array {
    unsigned int size;
    unsigned int capacity;
    int *data;
};

/* Create a new array */
struct array *array_new(unsigned int capacity);

/* Free all memory used by an array */
void array_free(struct array *arr);

/* Get the number of items in an array */
unsigned int array_size(struct array *arr);
