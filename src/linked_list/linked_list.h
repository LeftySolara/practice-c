/**
 * @file linked_list.h
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief A singly-linked list implementation with a tail pointer
 * @version 0.1
 * @date 2022-08-25
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node {
    int data;
    struct node *next;
};

struct linked_list {
    struct node *head;
    struct node *tail;
    unsigned int size;
};

/** Create a new list node */
struct node *node_init(int data);

/** Free memory used by a node */
void node_free(struct node *node);

/** Create a new linked list */
struct linked_list *linked_list_init();

/** Free memory used by a linked list */
void linked_list_free(struct linked_list *list);

/** Get the current size of a linked list */
unsigned int linked_list_size(struct linked_list *list);

/** Determine whether a linked list is empty */
int linked_list_empty(struct linked_list *list);

/** Get the value stored at a specific location in a list */
int linked_list_value_at(struct linked_list *list, unsigned int index);

/** Add an item to the front of a list */
void linked_list_push_front(struct linked_list *list, int data);

/** Add an item to the end of a list */
void linked_list_push_back(struct linked_list *list, int data);

#endif /* LINKED_LIST_H */