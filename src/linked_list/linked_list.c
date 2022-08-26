/**
 * @file linked_list.c
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief A singly-linked list implementation with a tail pointer
 * @version 0.1
 * @date 2022-08-25
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

#include <limits.h>
#include <stdlib.h>

#include "./linked_list.h"

/**
 * @brief Create a new list node
 *
 * @param data The data to store in the new node
 *
 * @return struct node* A new list node contrining the provided data
 */
struct node *node_init(int data)
{
    struct node *new_node = malloc(sizeof(*new_node));
    if (!new_node) {
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

/**
 * @brief Free the memory used by a list node
 *
 * @param node The node for free memory from
 */
void node_free(struct node *node)
{
    free(node);
}

/**
 * @brief Create a new linked list
 *
 * @return struct linked_list* Pointer to the new linked list structure
 */
struct linked_list *linked_list_init()
{
    struct linked_list *list = malloc(sizeof(*list));
    if (!list) {
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

/**
 * @brief Free the memory used by a linked list
 *
 * @param list The list to free memory from
 */
void linked_list_free(struct linked_list *list)
{
    if (!list) {
        return;
    }

    struct node *current = list->head;
    while (current) {
        list->head = current->next;
        node_free(current);
        current = list->head;
    }
    free(list);
}

/**
 * @brief Get the current size of a linked list
 *
 * @param list The list to check
 *
 * @return unsigned int The current size of the given list
 */
unsigned int linked_list_size(struct linked_list *list)
{
    if (!list) {
        return 0;
    }
    return list->size;
}

/**
 * @brief Determine whether a linked list is empty
 *
 * @param list The list to check
 *
 * @return int 1 if the list is empty, or 0 otherwise
 */
int linked_list_empty(struct linked_list *list)
{
    return (!list || list->size == 0);
}

/**
 * @brief Get the value stored at a specific location in a list
 *
 * @param list The list to check
 * @param index The position in the list to search for
 *
 * @return int The value stored at the index, or INT_MAX if the index is out of bounds
 */
int linked_list_value_at(struct linked_list *list, unsigned int index)
{
    if (!list || index >= list->size || list->size == 0) {
        return INT_MAX;
    }

    struct node *current = list->head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

/**
 * @brief Add an item to the front of a linked list
 *
 * @param list The list to add to
 * @param data The item to add to the list
 */
void linked_list_push_front(struct linked_list *list, int data)
{
    if (!list) {
        return;
    }

    struct node *new_node = node_init(data);

    if (!list->head) {
        list->head = new_node;
        list->tail = new_node;
    }
    else {
        new_node->next = list->head;
        list->head = new_node;
    }
    ++list->size;
}

/**
 * @brief Remove the first item in a list and return its value
 *
 * @param list The list to pop from
 *
 * @return int The value of the first item in the list
 */
int linked_list_pop_front(struct linked_list *list)
{
    if (!list || list->size == 0) {
        return INT_MAX;
    }

    struct node *current = list->head;
    list->head = list->head->next;

    int value = current->data;
    node_free(current);
    --list->size;

    return value;
}

/**
 * @brief Add an item to the end of a list
 *
 * @param list The list to append to
 * @param data The value to add to the list
 */
void linked_list_push_back(struct linked_list *list, int data)
{
    if (!list) {
        return;
    }

    struct node *new_node = node_init(data);

    if (!list->head) {
        list->head = new_node;
        list->tail = new_node;
    }
    else {
        struct node *current = list->tail;
        current->next = new_node;
        list->tail = new_node;
    }
    ++list->size;
}

/**
 * @brief Remove the last item in a list and return its value
 *
 * @param list The list to pop from
 *
 * @return int The value of the last item in the list
 */
int linked_list_pop_back(struct linked_list *list)
{
    if (!list || list->size == 0) {
        return INT_MAX;
    }

    int value = list->tail->data;

    if (list->size == 1) {
        node_free(list->head);
        list->head = NULL;
        list->tail = NULL;
    }
    else {
        struct node *current = list->head;
        while (current->next != list->tail) {
            current = current->next;
        }

        node_free(list->tail);
        list->tail = current;
    }
    --list->size;

    return value;
}
