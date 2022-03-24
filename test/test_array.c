#include "../src/array/array.h"
#include "../unity/src/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_array_size(void)
{
    struct array *arr = array_new(12);

    TEST_ASSERT_EQUAL(0, arr->size);

    array_free(arr);
}

void test_array_capacity(void)
{
    struct array *arr = array_new(12);

    TEST_ASSERT_EQUAL(12, array_capacity(arr));

    array_free(arr);
}

void test_array_resize(void)
{
    struct array *arr = array_new(8);

    array_resize(arr);
    TEST_ASSERT_EQUAL(4, array_capacity(arr));

    array_free(arr);
}

void test_array_is_empty(void)
{
    struct array *arr = array_new(8);
    TEST_ASSERT_EQUAL(1, array_is_empty(arr));

    array_push(arr, 4);
    TEST_ASSERT_EQUAL(0, array_is_empty(arr));
}

void test_array_push(void)
{
    struct array *arr = array_new(8);

    array_push(arr, 7);
    array_push(arr, 2);

    TEST_ASSERT_EQUAL(2, array_size(arr));
    TEST_ASSERT_EQUAL(8, array_capacity(arr));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_array_size);
    RUN_TEST(test_array_capacity);
    RUN_TEST(test_array_resize);
    RUN_TEST(test_array_is_empty);
    RUN_TEST(test_array_push);
    return UNITY_END();
}
