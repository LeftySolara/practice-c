/**
 * @file linked_list.h
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief A singly-linked list implementation with a tail pointer
 * @version 0.1
 * @date 2022-03-26
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct list {
    struct node *head;
    struct node *tail;

    size_t size;
};

/* Create a new list */
struct list *list_new();

/* Free memory used by a list */
void list_free(struct list *list);

/* Get the size of a list */
size_t list_size(struct list *list);