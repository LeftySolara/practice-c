#include "../src/vector/vector.h"
#include "../unity/src/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_vector_init(void)
{
    const unsigned int capacity = 16;
    struct vector *v = vector_init(capacity);

    TEST_ASSERT_NOT_NULL(v);
    TEST_ASSERT_NOT_NULL(v->data);
    TEST_ASSERT_EQUAL(0, v->size);
    TEST_ASSERT_EQUAL(capacity, v->capacity);

    vector_free(v);
}

void test_vector_upsize(void)
{
    const unsigned int capacity = 2;

    struct vector *v = vector_init(capacity);
    TEST_ASSERT_EQUAL(capacity, v->capacity);

    vector_upsize(v);
    TEST_ASSERT_EQUAL(capacity * 2, v->capacity);
    TEST_ASSERT_EQUAL(0, v->size);

    vector_free(v);
}

void test_vector_downsize(void)
{
    const unsigned int capacity = 4;

    struct vector *v = vector_init(capacity);
    TEST_ASSERT_EQUAL(capacity, v->capacity);

    vector_downsize(v);
    TEST_ASSERT_EQUAL(capacity / 2, v->capacity);
    TEST_ASSERT_EQUAL(0, v->size);

    vector_free(v);
}

void test_vector_at(void)
{
    struct vector *v = vector_init(4);

    vector_push(v, 13);
    vector_push(v, 3);
    vector_push(v, 9);

    TEST_ASSERT_EQUAL(13, vector_at(v, 0));
    TEST_ASSERT_EQUAL(3, vector_at(v, 1));
    TEST_ASSERT_EQUAL(9, vector_at(v, 2));

    vector_free(v);
}

void test_vector_push(void)
{
    struct vector *v = vector_init(2);
    vector_push(v, 13);
    vector_push(v, 3);

    /* Push to a full vector */
    vector_push(v, 9);

    TEST_ASSERT_EQUAL(13, vector_at(v, 0));
    TEST_ASSERT_EQUAL(3, vector_at(v, 1));
    TEST_ASSERT_EQUAL(9, vector_at(v, 2));

    TEST_ASSERT_EQUAL(3, v->size);
    TEST_ASSERT_EQUAL(4, v->capacity);

    vector_free(v);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_vector_init);
    RUN_TEST(test_vector_upsize);
    RUN_TEST(test_vector_downsize);
    RUN_TEST(test_vector_at);
    RUN_TEST(test_vector_push);
    return UNITY_END();
}
