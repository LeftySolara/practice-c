/**
 * @file binary_tree.c
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief Binary search tree implementation
 * @version 0.1
 * @date 2022-09-01
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

#include <stdlib.h>

#include "binary_tree.h"

/**
 * @brief Create a new binary tree node
 *
 * @param data The data to save in the node
 * @return struct node* A pointer to the new node
 */
struct node *node_init(int data)
{
    struct node *new_node = malloc(sizeof(*new_node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

/**
 * @brief Free memory used by a binary tree node
 *
 * @param node The node to free memory from
 */
void node_free(struct node *node)
{
    if (node) {
        free(node);
    }
}

/**
 * @brief Insert a new node into a binary tree
 *
 * @param root The root node of the tree
 * @param data The value to add to the tree
 *
 * @return struct node* A pointer to the new leaf node
 */
struct node *binary_tree_insert(struct node *root, const int data)
{
    if (!root) {
        return node_init(data);
    }

    if (data < root->data) {
        root->left = binary_tree_insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = binary_tree_insert(root->right, data);
    }

    return root;
}
