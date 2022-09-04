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
    RUN_TEST(test_binary_tree_print);
    return UNITY_END();
}
