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

/* Create a new list node */
struct node *node_new(int value);

/* Free memory used by a node */
void node_free(struct node *node);

/* Create a new list */
struct list *list_new();

/* Free memory used by a list */
void list_free(struct list *list);

/* Get the size of a list */
size_t list_size(struct list *list);

/* Determine whether a list is empty */
int list_empty(struct list *list);

/* Get the value of an item at a specific place in a list */
int list_value_at(struct list *list, unsigned int index);

/* Get the first item in a list */
int list_front(struct list *list);

/* Get the last item in a list */
int list_back(struct list *list);

/* Get the value of the nth item from the end of a list */
int list_value_n_from_end(struct list *list, int n);

/* Add an item to the front of a list */
void list_push_front(struct list *list, int value);

/* Add an item to the end of a list */
void list_push_back(struct list *list, int value);

/* Add an item to a specific place in a list */
void list_insert(struct list *list, unsigned int pos, int value);

/* Remove the first item in a list and return its value */
int list_pop_front(struct list *list);

/* Remove the last item in a list and return its value */
int list_pop_back(struct list *list);

/* Remove a node at the given index */
void list_erase(struct list *list, unsigned int index);

/* Remove the first item in a list with a given value */
void list_remove_value(struct list *list, int value);