#include "../src/linked_list/linked_list.h"
#include "../unity/src/unity.h"

struct list *test_list;
struct list *null_list;

void setUp(void)
{
    test_list = list_new();
    null_list = NULL;
}

void tearDown(void)
{
    list_free(test_list);
}

void test_list_size(void)
{
    TEST_ASSERT_EQUAL(0, list_size(null_list));
    TEST_ASSERT_EQUAL(0, list_size(test_list));
}

void test_list_push_back(void)
{
    list_push_back(null_list, 5);
    list_push_back(test_list, 3);
    list_push_back(test_list, 5);

    TEST_ASSERT_NULL(null_list);
    TEST_ASSERT_EQUAL(2, list_size(test_list));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_list_size);
    RUN_TEST(test_list_push_back);
    return UNITY_END();
}