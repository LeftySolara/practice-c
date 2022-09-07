#include "../src/priority_queue/priority_queue.h"
#include "../unity/src/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_priority_queue_insert(void)
{
    struct priority_queue *queue = priority_queue_init(1000);

    priority_queue_insert(queue, 5);
    priority_queue_insert(queue, 9);
    priority_queue_insert(queue, 16);
    priority_queue_insert(queue, 2);
    priority_queue_insert(queue, 17);
    priority_queue_insert(queue, 10);
    priority_queue_insert(queue, 12);
    priority_queue_insert(queue, 14);
    priority_queue_insert(queue, 6);

    printf("Insert Test: ");
    priority_queue_print(queue);

    priority_queue_free(queue);
}

void test_priority_queue_extract_max(void)
{
    struct priority_queue *queue = priority_queue_init(1000);

    priority_queue_insert(queue, 5);
    priority_queue_insert(queue, 9);
    priority_queue_insert(queue, 16);
    priority_queue_insert(queue, 2);
    priority_queue_insert(queue, 17);
    priority_queue_insert(queue, 10);
    priority_queue_insert(queue, 12);
    priority_queue_insert(queue, 14);
    priority_queue_insert(queue, 6);

    TEST_ASSERT_EQUAL(17, priority_queue_extract_max(queue));
    printf("Extract max test: ");
    priority_queue_print(queue);

    TEST_ASSERT_EQUAL(16, priority_queue_extract_max(queue));
    printf("Extract max test: ");
    priority_queue_print(queue);

    priority_queue_free(queue);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_priority_queue_insert);
    RUN_TEST(test_priority_queue_extract_max);
    return UNITY_END();
}
