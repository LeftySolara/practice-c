#include "../src/linked_list/linked_list.h"
#include "../unity/src/unity.h"

struct list *test_list;

void setUp(void)
{
    test_list = list_new();
}

void tearDown(void)
{
    list_free(test_list);
}

void test_list_size(void)
{
    TEST_ASSERT_EQUAL(0, list_size(test_list));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_list_size);
    return UNITY_END();
}