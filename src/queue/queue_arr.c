/**
 * @file queue_arr.c
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief A simple queue implementation using an array
 * @version 0.1
 * @date 2022-08-26
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

#include <stdlib.h>

#include "queue_arr.h"

/**
 * @brief Create a new queue
 *
 * @param capacity The maximum size of the queue
 *
 * @return struct queue_arr* A pointer to the new queue struct
 */
struct queue_arr *queue_arr_new(int capacity)
{
    struct queue_arr *queue = malloc(sizeof(struct queue_arr));
    queue->data = malloc(sizeof(int) * capacity);
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
    queue->capacity = capacity;

    return queue;
}

/**
 * @brief Free memory used by a queue
 *
 * @param queue The queue to free
 */
void queue_arr_free(struct queue_arr *queue)
{
    free(queue->data);
    free(queue);
}

/**
 * @brief Add an item to the queue
 *
 * @param queue The queue to add to
 * @param value The value of the item to add
 */
void queue_arr_enqueue(struct queue_arr *queue, int value)
{
    queue->data[queue->tail++] = value;
    queue->tail %= queue->capacity;
}

int queue_arr_dequeue(struct queue_arr *queue)
{
    int value = queue->data[queue->head++];
    queue->head %= queue->capacity;
    return value;
}
