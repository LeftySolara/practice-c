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
        free(current);
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