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

    array_free(arr);
}

void test_array_at(void)
{
    struct array *arr = array_new(8);

    array_push(arr, 5);
    array_push(arr, 2);
    array_push(arr, 7);

    TEST_ASSERT_EQUAL(5, array_at(arr, 0));
    TEST_ASSERT_EQUAL(2, array_at(arr, 1));
    TEST_ASSERT_EQUAL(7, array_at(arr, 2));

    array_free(arr);
}

void test_array_push(void)
{
    struct array *arr = array_new(8);

    array_push(arr, 7);
    array_push(arr, 2);

    TEST_ASSERT_EQUAL(2, array_size(arr));
    TEST_ASSERT_EQUAL(8, array_capacity(arr));
}

void test_array_insert(void)
{
    struct array *arr = array_new(8);

    array_push(arr, 4);
    array_push(arr, 9);
    array_push(arr, 6);
    array_push(arr, 10);

    array_insert(arr, 11, 0);
    array_insert(arr, 55, 2);

    TEST_ASSERT_EQUAL(11, array_at(arr, 0));
    TEST_ASSERT_EQUAL(4, array_at(arr, 1));
    TEST_ASSERT_EQUAL(55, array_at(arr, 2));
    TEST_ASSERT_EQUAL(9, array_at(arr, 3));
    TEST_ASSERT_EQUAL(6, array_at(arr, 4));
    TEST_ASSERT_EQUAL(10, array_at(arr, 5));

    array_free(arr);
}

void test_array_prepend(void)
{
    struct array *arr = array_new(8);

    array_push(arr, 4);
    array_push(arr, 9);
    array_prepend(arr, 19);

    TEST_ASSERT_EQUAL(19, array_at(arr, 0));
    TEST_ASSERT_EQUAL(4, array_at(arr, 1));
    TEST_ASSERT_EQUAL(9, array_at(arr, 2));

    array_free(arr);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_array_size);
    RUN_TEST(test_array_capacity);
    RUN_TEST(test_array_resize);
    RUN_TEST(test_array_is_empty);
    RUN_TEST(test_array_at);
    RUN_TEST(test_array_push);
    RUN_TEST(test_array_insert);
    RUN_TEST(test_array_prepend);
    return UNITY_END();
}
