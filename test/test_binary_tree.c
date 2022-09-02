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
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_binary_tree_insert);
    return UNITY_END();
}
