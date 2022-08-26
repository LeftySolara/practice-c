/**
 * @file queue_ll.h
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief A queue data structure implemented using a linked list
 * @version 0.1
 * @date 2022-08-26
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

#ifndef QUEUE_LL_H
#define QUEUE_LL_H

struct node {
    int data;
    struct node *next;
};

struct queue_ll {
    struct node *head;
    struct node *tail;
};

/** Create a new queue */
struct queue_ll *queue_ll_init();

/** Free memory used by a queue */
void queue_ll_free(struct queue_ll *queue);

/** Add an item to the end of a queue */
void queue_ll_enqueue(struct queue_ll *queue, int data);

/** Remove an item from the front of a queue and return it */
int queue_ll_dequeue(struct queue_ll *queue);

/** Check whether a queue is empty */
int queue_ll_empty(struct queue_ll *queue);

#endif /* QUEUE_LL_H */
