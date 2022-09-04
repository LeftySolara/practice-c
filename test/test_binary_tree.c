#include <limits.h>
#include <math.h>

#include "../src/binary_tree/binary_tree.h"
#include "../unity/src/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_binary_tree_insert(void)
{
    struct node *root = node_init(5);

    binary_tree_insert(root, 3);
    binary_tree_insert(root, 9);
    binary_tree_insert(root, 4);

    TEST_ASSERT_EQUAL(5, root->data);
    TEST_ASSERT_EQUAL(3, root->left->data);
    TEST_ASSERT_EQUAL(9, root->right->data);
    TEST_ASSERT_EQUAL(4, root->left->right->data);

    binary_tree_free(root);
}

void test_binary_tree_get_node_count(void)
{
    struct node *root = node_init(5);

    TEST_ASSERT_EQUAL(1, binary_tree_get_node_count(root));

    binary_tree_insert(root, 3);
    binary_tree_insert(root, 9);
    binary_tree_insert(root, 4);

    TEST_ASSERT_EQUAL(4, binary_tree_get_node_count(root));

    binary_tree_free(root);
}

void test_binary_tree_is_in_tree(void)
{
    struct node *root = node_init(5);

    binary_tree_insert(root, 17);
    binary_tree_insert(root, 3);
    binary_tree_insert(root, 20);
    binary_tree_insert(root, 14);

    TEST_ASSERT_EQUAL(0, binary_tree_is_in_tree(root, 100));
    TEST_ASSERT_EQUAL(1, binary_tree_is_in_tree(root, 5));
    TEST_ASSERT_EQUAL(1, binary_tree_is_in_tree(root, 20));

    binary_tree_free(root);
}

void test_binary_tree_get_height(void)
{
    struct node *root = node_init(15);

    TEST_ASSERT_EQUAL(1, binary_tree_get_height(root));

    binary_tree_insert(root, 10);
    binary_tree_insert(root, 7);
    binary_tree_insert(root, 12);
    binary_tree_insert(root, 9);
    binary_tree_insert(root, 22);
    binary_tree_insert(root, 20);
    binary_tree_insert(root, 18);
    binary_tree_insert(root, 16);

    TEST_ASSERT_EQUAL(5, binary_tree_get_height(root));

    binary_tree_free(root);
}

void test_binary_tree_get_min(void)
{
    struct node *root = node_init(15);

    binary_tree_insert(root, 10);
    binary_tree_insert(root, 7);
    binary_tree_insert(root, 12);
    binary_tree_insert(root, 9);
    binary_tree_insert(root, 22);
    binary_tree_insert(root, 20);
    binary_tree_insert(root, 18);
    binary_tree_insert(root, 16);

    TEST_ASSERT_EQUAL(7, binary_tree_get_min(root));

    binary_tree_free(root);
}

void test_binary_tree_get_max(void)
{
    struct node *root = node_init(15);

    binary_tree_insert(root, 10);
    binary_tree_insert(root, 7);
    binary_tree_insert(root, 12);
    binary_tree_insert(root, 9);
    binary_tree_insert(root, 22);
    binary_tree_insert(root, 20);
    binary_tree_insert(root, 18);
    binary_tree_insert(root, 16);

    TEST_ASSERT_EQUAL(22, binary_tree_get_max(root));

    binary_tree_free(root);
}

void test_binary_tree_is_bst(void)
{
    struct node *root = node_init(15);

    binary_tree_insert(root, 10);
    binary_tree_insert(root, 7);
    binary_tree_insert(root, 12);
    binary_tree_insert(root, 9);
    binary_tree_insert(root, 22);
    binary_tree_insert(root, 20);
    binary_tree_insert(root, 18);
    binary_tree_insert(root, 16);

    TEST_ASSERT_EQUAL(1, binary_tree_is_bst(root, INT_MIN, INT_MAX));

    binary_tree_free(root);
}

void test_binary_tree_print(void)
{
    struct node *root = node_init(5);

    binary_tree_insert(root, 3);
    binary_tree_insert(root, 9);
    binary_tree_insert(root, 4);
    binary_tree_insert(root, 14);
    binary_tree_insert(root, -3);

    binary_tree_print(root);

    binary_tree_free(root);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_binary_tree_insert);
    RUN_TEST(test_binary_tree_get_node_count);
    RUN_TEST(test_binary_tree_is_in_tree);
    RUN_TEST(test_binary_tree_get_height);
    RUN_TEST(test_binary_tree_get_min);
    RUN_TEST(test_binary_tree_get_max);
    RUN_TEST(test_binary_tree_is_bst);
    RUN_TEST(test_binary_tree_print);
    return UNITY_END();
}
