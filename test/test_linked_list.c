#include "../src/linked_list/linked_list.h"
#include "../unity/src/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_linked_list_init(void)
{
    struct linked_list *list = linked_list_init();

    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_NULL(list->head);
    TEST_ASSERT_NULL(list->tail);
    TEST_ASSERT_EQUAL(0, list->size);

    linked_list_free(list);
}

void test_linked_list_push_front(void)
{
    struct linked_list *list = linked_list_init();

    linked_list_push_front(list, 4);
    linked_list_push_front(list, 7);

    TEST_ASSERT_EQUAL(7, linked_list_value_at(list, 0));
    TEST_ASSERT_EQUAL(4, linked_list_value_at(list, 1));

    linked_list_free(list);
}

void test_linked_list_pop_front(void)
{
    struct linked_list *list = linked_list_init();

    linked_list_push_back(list, 14);
    linked_list_push_back(list, 3);
    linked_list_push_back(list, 7);

    TEST_ASSERT_EQUAL(14, linked_list_pop_front(list));
    TEST_ASSERT_EQUAL(3, linked_list_pop_front(list));
    TEST_ASSERT_EQUAL(1, linked_list_size(list));

    linked_list_free(list);
}

void test_linked_list_push_back(void)
{
    struct linked_list *list = linked_list_init();

    linked_list_push_back(list, 4);
    linked_list_push_back(list, 7);

    TEST_ASSERT_EQUAL(4, linked_list_value_at(list, 0));
    TEST_ASSERT_EQUAL(7, linked_list_value_at(list, 1));

    linked_list_free(list);
}

void test_linked_list_pop_back(void)
{
    struct linked_list *list = linked_list_init();

    linked_list_push_back(list, 14);
    linked_list_push_back(list, 3);
    linked_list_push_back(list, 7);

    TEST_ASSERT_EQUAL(7, linked_list_pop_back(list));
    TEST_ASSERT_EQUAL(3, linked_list_pop_back(list));
    TEST_ASSERT_EQUAL(1, linked_list_size(list));
}

void test_linked_list_front(void)
{
    struct linked_list *list = linked_list_init();

    linked_list_push_back(list, 14);
    linked_list_push_back(list, 3);
    linked_list_push_back(list, 7);

    TEST_ASSERT_EQUAL(14, linked_list_front(list));

    linked_list_free(list);
}

void test_linked_list_back(void)
{
    struct linked_list *list = linked_list_init();

    linked_list_push_back(list, 14);
    linked_list_push_back(list, 3);
    linked_list_push_back(list, 7);

    TEST_ASSERT_EQUAL(7, linked_list_back(list));

    linked_list_free(list);
}

void test_linked_list_insert(void)
{
    struct linked_list *list = linked_list_init();

    linked_list_push_back(list, 14);
    linked_list_push_back(list, 3);
    linked_list_push_back(list, 7);
    linked_list_insert(list, 2, 18);
    linked_list_insert(list, 0, 9);

    TEST_ASSERT_EQUAL(9, linked_list_front(list));
    TEST_ASSERT_EQUAL(18, linked_list_value_at(list, 3));

    linked_list_free(list);
}

void test_linked_list_erase(void)
{
    struct linked_list *list = linked_list_init();

    linked_list_push_back(list, 14);
    linked_list_push_back(list, 3);
    linked_list_push_back(list, 7);
    linked_list_erase(list, 1);

    TEST_ASSERT_EQUAL(7, linked_list_value_at(list, 1));
    TEST_ASSERT_EQUAL(2, linked_list_size(list));

    linked_list_free(list);
}

void test_linked_list_reverse(void)
{
    struct linked_list *list = linked_list_init();

    linked_list_push_back(list, 14);
    linked_list_push_back(list, 3);
    linked_list_push_back(list, 7);

    linked_list_reverse(list);

    TEST_ASSERT_EQUAL(7, linked_list_value_at(list, 0));
    TEST_ASSERT_EQUAL(3, linked_list_value_at(list, 1));
    TEST_ASSERT_EQUAL(14, linked_list_value_at(list, 2));

    linked_list_free(list);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_linked_list_init);
    RUN_TEST(test_linked_list_push_front);
    RUN_TEST(test_linked_list_pop_front);
    RUN_TEST(test_linked_list_push_back);
    RUN_TEST(test_linked_list_pop_back);
    RUN_TEST(test_linked_list_front);
    RUN_TEST(test_linked_list_back);
    RUN_TEST(test_linked_list_insert);
    RUN_TEST(test_linked_list_erase);
    RUN_TEST(test_linked_list_reverse);
    return UNITY_END();
}
