/**
 * @file priority_queue.h
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief A priority queue implementation using a max-heap
 * @version 0.1
 * @date 2022-09-06
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stddef.h>

struct priority_queue {
    unsigned int size;     /** The number of items currently in the queue. */
    unsigned int capacity; /** The maximum number of items the queue can hold. */
    int *data;             /** The items in the queue. */
};

/** Create a new priority queue. */
struct priority_queue *priority_queue_init(const unsigned int capacity);
/** Free memory used by a priority queue. */
void priority_queue_free(struct priority_queue *queue);

/** Display the contents of a priority queue. */
void priority_queue_print(struct priority_queue *queue);

/** Add an item to a priority queue. */
void priority_queue_insert(struct priority_queue *queue, int value);

/** Move a node up in a max-heap. */
void priority_queue_sift_up(struct priority_queue *queue, unsigned int index);
/** Move a node down in a max-heap. */
void priority_queue_sift_down(struct priority_queue *queue, unsigned int index);

/** Get the current size of a priority queue. */
unsigned int priority_queue_get_size(struct priority_queue *queue);
/** Check whether a priority queue is empty. */
int priority_queue_is_empty(struct priority_queue *queue);

/** Get the largest value in a priority queue. */
int priority_queue_get_max(struct priority_queue *queue);
int priority_queue_extract_max(struct priority_queue *queue);

void priority_queue_remove(struct priority_queue *queue, unsigned int index);

int *priority_queue_heapify(int *data);

void heap_sort(int *data);

#endif /* PRIORITY_QUEUE_H */
