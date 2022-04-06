/**
 * @file queue_ll.c
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief A simple queue implementation using a linked list
 * @version 0.1
 * @date 2022-04-06
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

#include "queue_ll.h"

#include <limits.h>
#include <stdlib.h>

/**
 * @brief Create a new, empty queue
 *
 * @return struct queue_ll* A pointer to the new queue
 */
struct queue_ll *queue_ll_new()
{
    struct queue_ll *new_queue = malloc(sizeof(struct queue_ll));
    new_queue->head = NULL;
    new_queue->tail = NULL;
    new_queue->size = 0;

    return new_queue;
}

/**
 * @brief Free memory used by a queue
 *
 * @param queue The queue to free
 */
void queue_ll_free(struct queue_ll *queue)
{
    if (!queue) {
        return;
    }

    struct node *current = queue->head;
    while (current) {
        queue->head = current->next;
        free(current);
        current = queue->head;
    }
    free(queue);
}

/**
 * @brief Add a value at the end of the queue
 *
 * @param value The value to add to the queue
 */
void queue_ll_enqueue(struct queue_ll *queue, int value)
{
    if (!queue) {
        return;
    }

    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;

    if (!queue->head) {
        queue->head = new_node;
        queue->tail = new_node;
    }
    else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
    ++queue->size;
}

/**
 * @brief Remove a value from the front of a queue and return it
 *
 * @param queue The queue to get the item from
 * @return int The value of the item
 */
int queue_ll_dequeue(struct queue_ll *queue)
{
    if (!queue || queue->size == 0) {
        return INT_MAX;
    }

    int value = queue->head->data;

    struct node *current = queue->head;
    queue->head = queue->head->next;
    free(current);
    --queue->size;

    return value;
}

/**
 * @brief Determine whether a queue is empty
 *
 * @param queue The queue to check
 * @return int Returns 1 if the queue is empty, or 0 otherwise
 */
int queue_ll_empty(struct queue_ll *queue)
{
    return queue->size == 0;
}