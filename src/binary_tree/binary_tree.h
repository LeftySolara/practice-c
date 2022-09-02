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

struct node *binary_tree_insert(struct node *root, const int data);

#endif /* BINARY_TREE_H */
