#include "../src/hash_table/hash_table.h"
#include "../unity/src/unity.h"

struct hash_table *table;

void setUp(void)
{
    table = hash_table_new(7);
}

void tearDown(void)
{
    hash_table_free(table);
}

void test_hash_table_hash(void)
{
    size_t result = hash("one", table->size);
    TEST_ASSERT_TRUE(result >= 0 && result < table->size);

    /* Make sure we get the same value from hashing the same key */
    size_t result2 = hash("one", table->size);
    TEST_ASSERT_TRUE(result2 >= 0 && result2 < table->size);

    result = hash("", table->size);
    TEST_ASSERT_TRUE(result >= 0 && result < table->size);
}

void test_hash_table_add(void)
{
    hash_table_add(table, "one", 1);
    hash_table_add(table, "two", 2);
    hash_table_add(table, "three", 3);

    TEST_ASSERT_TRUE(hash_table_key_exists(table, "one"));
    TEST_ASSERT_TRUE(hash_table_key_exists(table, "two"));
    TEST_ASSERT_TRUE(hash_table_key_exists(table, "three"));
    TEST_ASSERT_FALSE(hash_table_key_exists(table, "four"));
}

void test_hash_table_get(void)
{
    hash_table_add(table, "one", 1);
    TEST_ASSERT_EQUAL(1, hash_table_get(table, "one"));
    TEST_ASSERT_EQUAL(INT_MIN, hash_table_get(table, "two"));
}

void test_hash_table_remove(void)
{
    hash_table_add(table, "one", 1);
    hash_table_add(table, "two", 2);

    hash_table_remove(table, "one");

    TEST_ASSERT_FALSE(hash_table_key_exists(table, "one"));
    TEST_ASSERT_TRUE(hash_table_key_exists(table, "two"));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_hash_table_hash);
    RUN_TEST(test_hash_table_add);
    RUN_TEST(test_hash_table_get);
    RUN_TEST(test_hash_table_remove);
    return UNITY_END();
}
