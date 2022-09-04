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

#include "binary_tree.h"

#include <stdio.h>
#include <stdlib.h>

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
 * @brief Free all memory used by a binary tree
 *
 * @param root The root node of the tree
 */
void binary_tree_free(struct node *root)
{
    if (!root) {
        return;
    }

    binary_tree_free(root->left);
    binary_tree_free(root->right);

    free(root);
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

/**
 * @brief Count the number of nodes in a tree
 *
 * @param root The tree to count

 * @return int The number of nodes in the tree
 */
int binary_tree_get_node_count(struct node *root)
{
    unsigned int cnt = 0;

    if (!root) {
        return 0;
    }

    cnt = 1 + binary_tree_get_node_count(root->left) + binary_tree_get_node_count(root->right);

    return cnt;
}

/**
 * @brief Print the values in a tree, from min to max
 *
 * @param root The root node of the tree to print
 */
void binary_tree_print(struct node *root)
{
    if (!root) {
        return;
    }

    binary_tree_print(root->left);
    printf("%d ", root->data);
    binary_tree_print(root->right);
}