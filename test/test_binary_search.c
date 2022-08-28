#include "../src/binary_search/binary_search.h"
#include "../unity/src/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_binary_search(void)
{
    int arr[] = {1, 3, 6, 8, 12, 17, 24, 28, 31, 32, 37, 41, 43, 49, 55};

    TEST_ASSERT_EQUAL(-1, binary_search(arr, 22, 15));
    TEST_ASSERT_EQUAL(0, binary_search(arr, 1, 15));
    TEST_ASSERT_EQUAL(14, binary_search(arr, 55, 15));
    TEST_ASSERT_EQUAL(9, binary_search(arr, 32, 15));
}

void test_binary_search_recursive(void)
{
    int arr[] = {1, 3, 6, 8, 12, 17, 24, 28, 31, 32, 37, 41, 43, 49, 55};

    TEST_ASSERT_EQUAL(-1, binary_search_recursive(arr, 22, 0, 14));
    TEST_ASSERT_EQUAL(0, binary_search_recursive(arr, 1, 0, 14));
    TEST_ASSERT_EQUAL(14, binary_search_recursive(arr, 55, 0, 14));
    TEST_ASSERT_EQUAL(9, binary_search_recursive(arr, 32, 0, 14));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_binary_search);
    RUN_TEST(test_binary_search_recursive);
    return UNITY_END();
}
