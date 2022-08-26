/**
 * @file queue_ll.c
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief A queue data structure implemented using a linked list
 * @version 0.1
 * @date 2022-08-26
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

#include <limits.h>
#include <stdlib.h>

#include "queue_ll.h"

/**
 * @brief Create a new queue
 *
 * @return struct queue_ll* A pointer to the new queue structure
 */
struct queue_ll* queue_ll_init()
{
    struct queue_ll* queue = malloc(sizeof(*queue));
    if (!queue) {
        return NULL;
    }

    queue->head = NULL;
    queue->tail = NULL;

    return queue;
}

/**
 * @brief Free memory used by a queue
 *
 * @param queue The queue to free memory from
 */
void queue_ll_free(struct queue_ll* queue)
{
    if (!queue) {
        return;
    }

    /* Traverse the linked list and delete all nodes */
    struct node* current = queue->head;
    while (current) {
        queue->head = current->next;
        free(current);
        current = queue->head;
    }
    free(queue);
}

/**
 * @brief Add an item to the end of a queue
 *
 * @param queue The queue to append to
 * @param data The item to add to the queue
 */
void queue_ll_enqueue(struct queue_ll* queue, int data)
{
    if (!queue) {
        return;
    }

    struct node* new_node = malloc(sizeof(*new_node));
    new_node->data = data;
    new_node->next = NULL;

    if (!queue->head) {
        queue->head = new_node;
        queue->tail = new_node;
    }
    else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
}

/**
 * @brief Remove an item from the front of a queue and return it
 *
 * @param queue The queue to remove an item from
 *
 * @return int The value of the first item in the queue, or INT_MAX if the queue is empty
 */
int queue_ll_dequeue(struct queue_ll* queue)
{
    if (!queue->head) {
        return INT_MAX;
    }

    const int value = queue->head->data;

    struct node* to_delete = queue->head;
    queue->head = queue->head->next;
    free(to_delete);

    return value;
}

/**
 * @brief Check whether a queue is empty
 *
 * @param queue The queue to check
 *
 * @return int 1 if the queue is empty, or 0 otherwise
 */
int queue_ll_empty(struct queue_ll* queue)
{
    return (!queue || !queue->head);
}
