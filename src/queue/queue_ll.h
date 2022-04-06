/**
 * @file queue_ll.h
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief A simple queue implementation using a linked list
 * @version 0.1
 * @date 2022-04-06
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

/**
 * @brief A node in a linked list
 */
struct node {
    int data;
    struct node *next;
};

/**
 * @brief A non-circular queue, implemented using a linked list
 */
struct queue_ll {
    struct node *head;
    struct node *tail;
    int size;
};

struct queue_ll *queue_ll_new();

void queue_ll_free(struct queue_ll *queue);

void queue_ll_enqueue(struct queue_ll *queue, int value);

int queue_ll_dequeue(struct queue_ll *queue);

int queue_ll_empty(struct queue_ll *queue);