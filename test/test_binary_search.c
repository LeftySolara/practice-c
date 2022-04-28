#include "../src/binary_search/binary_search.h"
#include "../src/hash_table/hash_table.h"
#include "../unity/src/unity.h"

int arr[] = {1, 3, 6, 8, 12, 17, 24, 28, 31, 32, 37, 41, 43, 49, 55};

void setUp(void)
{
}

void tearDown(void)
{
}

void test_binary_search(void)
{
    TEST_ASSERT_EQUAL(-1, binary_search(arr, 22, 15));
    TEST_ASSERT_EQUAL(0, binary_search(arr, 1, 15));
    TEST_ASSERT_EQUAL(14, binary_search(arr, 55, 15));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_binary_search);
    return UNITY_END();
}
