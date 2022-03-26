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

void test_list_empty(void)
{
    TEST_ASSERT_EQUAL(1, list_empty(test_list));
    TEST_ASSERT_EQUAL(1, list_empty(null_list));

    list_push_back(test_list, 5);
    TEST_ASSERT_EQUAL(0, list_empty(test_list));
}

void test_list_value_at(void)
{
    TEST_ASSERT_EQUAL(INT_MAX, list_value_at(null_list, 0));
    TEST_ASSERT_EQUAL(INT_MAX, list_value_at(test_list, 0));

    list_push_back(test_list, 4);
    list_push_back(test_list, 29);
    list_push_back(test_list, 15);

    TEST_ASSERT_EQUAL(4, list_value_at(test_list, 0));
    TEST_ASSERT_EQUAL(29, list_value_at(test_list, 1));
    TEST_ASSERT_EQUAL(15, list_value_at(test_list, 2));
}

void test_list_front(void)
{
    list_push_back(test_list, 3);
    list_push_back(test_list, 5);
    list_push_back(test_list, 12);

    TEST_ASSERT_EQUAL(3, list_front(test_list));
}

void test_list_back(void)
{
    list_push_back(test_list, 3);
    list_push_back(test_list, 5);
    list_push_back(test_list, 12);

    TEST_ASSERT_EQUAL(12, list_back(test_list));
}

void test_list_value_n_from_end(void)
{
    list_push_back(test_list, 3);
    list_push_back(test_list, 5);
    list_push_back(test_list, 12);
    list_push_back(test_list, 6);
    list_push_back(test_list, 19);

    TEST_ASSERT_EQUAL(19, list_value_n_from_end(test_list, 0));
    TEST_ASSERT_EQUAL(3, list_value_n_from_end(test_list, 4));
    TEST_ASSERT_EQUAL(12, list_value_n_from_end(test_list, 2));
}

void test_list_push_front(void)
{
    list_push_front(test_list, 3);
    list_push_front(test_list, 5);
    list_push_front(test_list, 9);

    TEST_ASSERT_EQUAL(9, list_value_at(test_list, 0));
    TEST_ASSERT_EQUAL(5, list_value_at(test_list, 1));
    TEST_ASSERT_EQUAL(3, list_value_at(test_list, 2));
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
    RUN_TEST(test_list_empty);
    RUN_TEST(test_list_value_at);
    RUN_TEST(test_list_front);
    RUN_TEST(test_list_back);
    RUN_TEST(test_list_value_n_from_end);
    RUN_TEST(test_list_push_front);
    RUN_TEST(test_list_push_back);
    return UNITY_END();
}
