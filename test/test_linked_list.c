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

void test_linked_list_push_back(void)
{
    struct linked_list *list = linked_list_init();

    linked_list_push_back(list, 4);
    linked_list_push_back(list, 7);

    TEST_ASSERT_EQUAL(4, linked_list_value_at(list, 0));
    TEST_ASSERT_EQUAL(7, linked_list_value_at(list, 1));

    linked_list_free(list);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_linked_list_init);
    RUN_TEST(test_linked_list_push_front);
    RUN_TEST(test_linked_list_push_back);
    return UNITY_END();
}
