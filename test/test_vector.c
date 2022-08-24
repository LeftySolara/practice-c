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

void test_vector_insert(void)
{
    struct vector *v = vector_init(4);

    vector_push(v, 5);
    vector_push(v, 9);
    vector_push(v, 4);
    vector_push(v, 8);

    vector_insert(v, 10, 2);
    TEST_ASSERT_EQUAL(10, vector_at(v, 2));
    TEST_ASSERT_EQUAL(5, v->size);

    vector_free(v);
}

void test_vector_prepend(void)
{
    struct vector *v = vector_init(4);

    vector_push(v, 5);
    vector_push(v, 9);
    vector_push(v, 4);
    vector_prepend(v, 8);

    TEST_ASSERT_EQUAL(8, vector_at(v, 0));
    TEST_ASSERT_EQUAL(5, vector_at(v, 1));

    vector_free(v);
}

void test_vector_pop(void)
{
    struct vector *v = vector_init(4);

    vector_push(v, 12);
    vector_push(v, 3);

    TEST_ASSERT_EQUAL(3, vector_pop(v));
    TEST_ASSERT_EQUAL(12, vector_pop(v));

    vector_free(v);
}

void test_vector_delete(void)
{
    struct vector *v = vector_init(4);

    vector_push(v, 13);
    vector_push(v, 4);
    vector_push(v, 17);
    vector_push(v, 8);

    vector_delete(v, 2);

    TEST_ASSERT_EQUAL(13, vector_at(v, 0));
    TEST_ASSERT_EQUAL(4, vector_at(v, 1));
    TEST_ASSERT_EQUAL(8, vector_at(v, 2));
    TEST_ASSERT_EQUAL(3, v->size);

    vector_free(v);
}

void test_vector_remove(void)
{
    struct vector *v = vector_init(4);

    vector_push(v, 13);
    vector_push(v, 4);
    vector_push(v, 17);
    vector_push(v, 8);

    vector_remove(v, 17);
    TEST_ASSERT_EQUAL(8, vector_at(v, 2));

    vector_remove(v, 100);
    TEST_ASSERT_EQUAL(3, v->size);

    vector_free(v);
}

void test_vector_find(void)
{
    struct vector *v = vector_init(4);

    vector_push(v, 4);
    vector_push(v, 17);
    vector_push(v, 8);

    TEST_ASSERT_EQUAL(1, vector_find(v, 17));

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
    RUN_TEST(test_vector_insert);
    RUN_TEST(test_vector_prepend);
    RUN_TEST(test_vector_pop);
    RUN_TEST(test_vector_delete);
    RUN_TEST(test_vector_remove);
    RUN_TEST(test_vector_find);
    return UNITY_END();
}
