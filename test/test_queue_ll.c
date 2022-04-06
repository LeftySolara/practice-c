#include "../src/queue/queue_ll.h"
#include "../unity/src/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_queue_enqueue(void)
{
    struct queue_ll *queue = queue_ll_new();
    queue_ll_enqueue(queue, 5);
    queue_ll_enqueue(queue, 2);

    TEST_ASSERT_EQUAL(2, queue->size);
    queue_ll_free(queue);
}

void test_queue_dequeue(void)
{
    struct queue_ll *queue = queue_ll_new();

    queue_ll_enqueue(queue, 5);
    queue_ll_enqueue(queue, 2);

    TEST_ASSERT_EQUAL(5, queue_ll_dequeue(queue));
    TEST_ASSERT_EQUAL(2, queue_ll_dequeue(queue));

    queue_ll_free(queue);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_queue_enqueue);
    RUN_TEST(test_queue_dequeue);
    return UNITY_END();
}
