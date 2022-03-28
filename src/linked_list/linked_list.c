/**
 * @file linked_list.c
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief A singly-linked list implementation with a tail pointer
 * @version 0.1
 * @date 2022-03-26
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

#include "linked_list.h"

#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * @brief Create a new list node
 *
 * @param value The node's data
 * @return struct node* Pointer to a new list node
 */
struct node *node_new(int value)
{
    struct node *new_node = malloc(sizeof(*new_node));
    new_node->data = value;
    new_node->next = NULL;

    return new_node;
}

/**
 * @brief Free memory used by a node
 *
 * @param node The node to free
 */
void node_free(struct node *node)
{
    free(node);
}

/**
 * @brief Create a new, empty linked list
 *
 * @return struct list* A pointer to the new list
 */
struct list *list_new()
{
    struct list *list = malloc(sizeof(*list));
    if (!list) {
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

/**
 * @brief Free memory used by a list
 *
 * @param list The list to free
 */
void list_free(struct list *list)
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
 * @brief Get the size of a list
 *
 * @param list The list to check
 * @return size_t The number of items in the list
 */
size_t list_size(struct list *list)
{
    if (!list) {
        return 0;
    }
    return list->size;
}

/**
 * @brief Determine whether a list is empty
 *
 * @param list The list to check
 * @return int Returns 1 if the list is empty, or 0 otherwise
 */
int list_empty(struct list *list)
{
    return (!list || list->size == 0);
}

/**
 * @brief Get the value of an item at a specific place in a list
 *
 * @param list The list to check
 * @param index The place in the list to check
 * @return int The value of the item at the given index, or UINT_MAX if index is out of bounds
 */
int list_value_at(struct list *list, unsigned int index)
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
 * @brief Get the first value in a list
 *
 * @param list The list to check
 * @return int The value of the first item in the list
 */
int list_front(struct list *list)
{
    if ((list_empty(list))) {
        return INT_MAX;
    }
    return list->head->data;
}

/**
 * @brief Get the last value in a list
 *
 * @param list The list to check
 * @return int The value of the last item in the list
 */
int list_back(struct list *list)
{
    if (list_empty(list)) {
        return INT_MAX;
    }
    return list->tail->data;
}

/**
 * @brief Get the value of the nth item from the end of a list
 *
 * @param list The list to check
 * @param n The number of items from the end of the list to check
 * @return int The value of the found item
 */
int list_value_n_from_end(struct list *list, int n)
{
    if (list_empty(list) || n >= list->size) {
        return INT_MAX;
    }

    int index = list->size - n - 1;
    return list_value_at(list, index);
}

/**
 * @brief Add an item to the front of a list
 *
 * @param list The list to add to
 * @param value The value to add to the list
 */
void list_push_front(struct list *list, int value)
{
    if (!list) {
        return;
    }

    struct node *new_node = node_new(value);

    if (list_empty(list)) {
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
 * @brief Add an item to the end of a list
 *
 * @param list The list to add to
 * @param value The item to add to the list
 */
void list_push_back(struct list *list, int value)
{
    if (!list) {
        return;
    }

    struct node *new_node = node_new(value);

    /* The list is empty */
    if (!list->head) {
        list->head = new_node;
        list->tail = new_node;
    }
    else {
        struct node *current = list->head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
        list->tail = new_node;
    }
    ++list->size;
}

/**
 * @brief Remove the first item in a list and return its value
 *
 * @param list The list to remove an item from
 * @return int The value of the first item in the list
 */
int list_pop_front(struct list *list)
{
    if (list_empty(list)) {
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
 * @brief Remove the last item in a list and return its value
 *
 * @param list The list to remove an item from
 * @return int The value of the last item in the list
 */
int list_pop_back(struct list *list)
{
    if (list_empty(list)) {
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
        list->tail->next = NULL;
    }
    --list->size;

    return value;
}

/**
 * @brief Remove a node at the given index
 *
 * @param list The list to remove an item from
 * @param index The place in the list to remove
 */
void list_erase(struct list *list, unsigned int index)
{
    if (list_empty(list) || index >= list->size) {
        return;
    }

    if (list->size == 1) {
        node_free(list->head);
        list->head = NULL;
        list->tail = NULL;
    }
    else {
        if (index == 0) {
            list_pop_front(list);
        }
        else if (index == list->size - 1) {
            list_pop_back(list);
        }
        else {
            struct node *current = list->head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }

            struct node *to_delete = current->next;
            current->next = to_delete->next;
            node_free(to_delete);
            --list->size;
        }
    }
}

/**
 * @brief Remove the first item in a list with a given value
 *
 * @param list The list to remove an item from
 * @param value The value of the item to remove
 */
void list_remove_value(struct list *list, int value)
{
    if (list_empty(list)) {
        return;
    }

    if (list->head->data == value) {
        list_pop_front(list);
    }
    else {
        struct node *current = list->head;
        while (current) {
            if (current->next->data == value) {
                struct node *to_delete = current->next;
                current->next = to_delete->next;
                node_free(to_delete);
                break;
            }
            current = current->next;
        }
        --list->size;
    }
}