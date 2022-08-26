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

/** Get the value of the node at the nth position from the end of a list */
int linke_list_value_n_from_end(struct linked_list *list, unsigned int n);

/** Add an item to the front of a list */
void linked_list_push_front(struct linked_list *list, int data);

/** Remove the first item in a list and return its value */
int linked_list_pop_front(struct linked_list *list);

/** Add an item to the end of a list */
void linked_list_push_back(struct linked_list *list, int data);

/** Remove the last item in a list and return its value */
int linked_list_pop_back(struct linked_list *list);

/** Get the value of the first item in a list */
int linked_list_front(struct linked_list *list);

/** Get the value of the last item in a list */
int linked_list_back(struct linked_list *list);

/** Insert an item at a specific index in a list */
void linked_list_insert(struct linked_list *list, unsigned int index, int data);

/** Remove an item at a specific index in a list */
void linked_list_erase(struct linked_list *list, unsigned int index);

/** Remove the first occurrance of a given value from a list */
void linked_list_remove_value(struct linked_list *list, int value);

/** Reverse a list */
void linked_list_reverse(struct linked_list *list);

#endif /* LINKED_LIST_H */
