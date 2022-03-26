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

#include <stddef.h>
#include <stdlib.h>

#include "linked_list.h"

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