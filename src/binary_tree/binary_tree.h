/**
 * @file binary_tree.h
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief Binary search tree implementation
 * @version 0.1
 * @date 2022-09-01
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *node_init(int data);
void node_free(struct node *node);
void binary_tree_free(struct node *root);

struct node *binary_tree_insert(struct node *root, const int data);

unsigned int binary_tree_get_node_count(struct node *root);
unsigned int binary_tree_get_height(struct node *root);
int binary_tree_get_min(struct node *root);
int binary_tree_get_max(struct node *root);

int binary_tree_is_in_tree(struct node *root, int data);
int binary_tree_is_bst(struct node *root, int min, int max);

void binary_tree_print(struct node *root);

#endif /* BINARY_TREE_H */
