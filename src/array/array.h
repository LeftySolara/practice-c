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

/* Update an array's capacity */
void array_resize(struct array *arr);

/* Double the capacity of an array */
void array_upsize(struct array *arr);

/* Half the capacity of an array */
void array_downsize(struct array *arr);

/* Get the number of items in an array */
unsigned int array_size(struct array *arr);

/* Get the number of items an array can hold */
unsigned int array_capacity(struct array *arr);

/* Determine whether an array is empty */
int array_is_empty(struct array *arr);

/* Get the item at a given index of an array */
int array_at(struct array *arr, unsigned int index);

/* Add a new item to the end of the array */
void array_push(struct array *arr, int value);

/* Add an item to an array at the given index */
void array_insert(struct array *arr, int value, unsigned int index);

/* Add an item to the beginning of an array */
void array_prepend(struct array *arr, int value);

/* Remove the last element in an array and return it */
int array_pop(struct array *arr);

/* Remove an item from an array at a given index */
void array_delete(struct array *arr, unsigned int index);

/* Remove an item from an array based on its value */
void array_remove(struct array *arr, int value);

/* Find an item in an array */
unsigned int array_find(struct array *arr, int value);
