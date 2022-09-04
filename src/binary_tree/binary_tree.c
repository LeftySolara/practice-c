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

#include <limits.h>
#include <stdio.h>
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
unsigned int binary_tree_get_node_count(struct node *root)
{
    unsigned int cnt = 0;

    if (!root) {
        return 0;
    }

    cnt = 1 + binary_tree_get_node_count(root->left) + binary_tree_get_node_count(root->right);

    return cnt;
}

/**
 * @brief Get the height of a binary tree
 *
 * @param root The tree to check
 *
 * @return unsigned int The height of the tree
 */
unsigned int binary_tree_get_height(struct node *root)
{
    if (!root) {
        return 0;
    }

    unsigned int left_height = binary_tree_get_height(root->left);
    unsigned int right_height = binary_tree_get_height(root->right);

    if (left_height >= right_height) {
        return left_height + 1;
    }
    else {
        return right_height + 1;
    }
}

/**
 * @brief Get the minimum value in a tree
 *
 * @param root The tree to search
 *
 * @return int The minumum value in the tree
 */
int binary_tree_get_min(struct node *root)
{
    if (!root) {
        return INT_MAX;
    }

    int min = root->data;
    int left_min;
    int right_min;

    if (root->left) {
        left_min = binary_tree_get_min(root->left);
        if (left_min < min) {
            min = left_min;
        }
    }
    if (root->right) {
        right_min = binary_tree_get_min(root->right);
        if (right_min < min) {
            min = right_min;
        }
    }

    return min;
}

/**
 * @brief Get the maximum value in a tree
 *
 * @param root The tree to search
 *
 * @return int The maximum value in the tree
 */
int binary_tree_get_max(struct node *root)
{
    if (!root) {
        return INT_MAX;
    }

    int max = root->data;
    int left_max;
    int right_max;

    if (root->left) {
        left_max = binary_tree_get_max(root->left);
        if (left_max > max) {
            max = left_max;
        }
    }
    if (root->right) {
        right_max = binary_tree_get_max(root->right);
        if (right_max > max) {
            max = right_max;
        }
    }

    return max;
}

/**
 * @brief Check if a value is in a tree
 *
 * @param root The tree to search
 * @param data The value to search for
 *
 * @return int 1 if the value is found, or 0 otherwise
 */
int binary_tree_is_in_tree(struct node *root, int data)
{
    if (!root) {
        return 0;
    }

    if (root->data == data) {
        return 1;
    }
    else if (root->data > data) {
        return binary_tree_is_in_tree(root->left, data);
    }
    else {
        return binary_tree_is_in_tree(root->right, data);
    }
}

/**
 * @brief Check whether a binary tree is a binary search tree
 *
 * @param root The tree to check
 * @param min The minimum value to check the tree against
 * @param max The maximum value to check the tree against
 *
 * @return int 1 if the tree is a BST, 0 otherwise
 */
int binary_tree_is_bst(struct node *root, int min, int max)
{
    if (!root) {
        return 1;
    }

    if (root->data <= min || root->data >= max) {
        return 0;
    }

    return binary_tree_is_bst(root->left, min, root->data) &&
           binary_tree_is_bst(root->right, root->data, max);
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
