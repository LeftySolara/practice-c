/**
 * @file vector.h
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief A dynamically-resizing array implementation
 * @version 0.1
 * @date 2022-08-23
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

#ifndef VECTOR_H
#define VECTOR_H

struct vector {
    unsigned int capacity;
    unsigned int size;
    int *data;
};

/** Create a new vector */
struct vector *vector_init(unsigned int capacity);

/** Free memory used by a vector */
void vector_free(struct vector *vector);

/** Double the capacity of a vector */
void vector_upsize(struct vector *vector);

/** Half the capacity of a vector */
void vector_downsize(struct vector *vector);

/** Get the current size of a vector */
unsigned int vector_size(struct vector *vector);

/** Get the current max capacity of a vector */
unsigned int vector_capacity(struct vector *vector);

/** Check whether a vector is empty */
int vector_is_empty(struct vector *vector);

/** Fetch the item at a specific index */
int vector_at(struct vector *vector, unsigned int index);

/** Add an item to the end of a vector */
void vector_push(struct vector *vector, int item);

/** Insert an item at a specific index */
void vector_insert(struct vector *vector, int item, int unsigned index);

/** Add an item at the beginning of a vector */
void vector_prepend(struct vector *vector, int item);

/** Remove the last item in a vector and return its value */
int vector_pop(struct vector *vector);

/** Remove the item at a given index */
void vector_delete(struct vector *vector, unsigned int index);

/** Remove a specific item from a vector */
void vector_remove(struct vector *vector, int item);

/** Find the index of an item in a vector */
unsigned int vector_find(struct vector *vector, int item);

#endif /* VECTOR_H */