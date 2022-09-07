/**
 * @file priority_queue.c
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief A priority queue implementation using a max-heap
 * @version 0.1
 * @date 2022-09-06
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "priority_queue.h"

/**
 * @brief Create a new priority queue.
 *
 * @param capacity The maximum number of items the queue should be able to hold.
 *
 * @return struct priority_queue* A pointer to a new priority queue structure.
 */
struct priority_queue *priority_queue_init(const unsigned int capacity)
{
    struct priority_queue *queue = malloc(sizeof(*queue));
    queue->data = malloc(sizeof(int) * capacity);
    queue->capacity = capacity;
    queue->size = 0;

    return queue;
}

/**
 * @brief Free memory used by a priority queue.
 *
 * @param queue The priority queue to free memory from.
 */
void priority_queue_free(struct priority_queue *queue)
{
    if (queue) {
        free(queue->data);
        free(queue);
    }
}

/**
 * @brief Display the contents of a priority queue.
 *
 * @param queue The queue to print.
 */
void priority_queue_print(struct priority_queue *queue)
{
    for (unsigned int i = 0; i < queue->size; ++i) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

/**
 * @brief Add an item to a priority queue.
 *
 * @param queue The queue to add to.
 * @param value The value of the new item.
 */
void priority_queue_insert(struct priority_queue *queue, int value)
{
    if (queue->size == queue->capacity) {
        printf("Cannot add more items.\n");
        return;
    }

    if (queue->size == 0) {
        queue->data[0] = value;
        ++queue->size;
        return;
    }

    queue->data[queue->size] = value;
    priority_queue_sift_up(queue, queue->size);
    ++queue->size;
}

/**
 * @brief Move a node up in a max-heap.
 *
 * @param queue The queue/heap to manipulate.
 * @param index The index of the node to sift.
 */
void priority_queue_sift_up(struct priority_queue *queue, unsigned int index)
{
    unsigned int parent_index = index / 2;

    /** Subtree satisfies the max-heap property, or is the root node. */
    if (index <= 0 || queue->data[parent_index] >= queue->data[index]) {
        return;
    }

    /* Swap the parent and child. */
    int temp = queue->data[index];
    queue->data[index] = queue->data[parent_index];
    queue->data[parent_index] = temp;

    priority_queue_sift_up(queue, parent_index);
}

/**
 * @brief Move a node down in a max heap.
 *
 * @param queue The queue to manipulate.
 * @param index The index of the node to sift.
 */
void priority_queue_sift_down(struct priority_queue *queue, unsigned int index)
{
}

/**
 * @brief Get the current size of a priority queue.
 *
 * @param queue The queue to check.
 *
 * @return unsigned int The current number of items in the queue.
 */
unsigned int priority_queue_get_size(struct priority_queue *queue)
{
    return queue->size;
}

/**
 * @brief Check whether a priority queue is empty.
 *
 * @param queue The queue to check.
 *
 * @return int 1 if the queue is empty, or 0 otherwise.
 */
int priority_queue_is_empty(struct priority_queue *queue)
{
    return queue->size == 0;
}

/**
 * @brief Get the largest value in a priority queue.
 *
 * @param queue The queue to check.
 *
 * @return int The largest value in the priority queue.
 */
int priority_queue_get_max(struct priority_queue *queue)
{
    if (queue && queue->data) {
        return queue->data[0];
    }
    return INT_MAX;
}
