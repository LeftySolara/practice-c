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

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_array_size);
    return UNITY_END();
}