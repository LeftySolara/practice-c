#include "../src/queue//queue_ll.h"
#include "../unity/src/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_queue_ll_init(void)
{
    struct queue_ll *queue = queue_ll_init();

    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_NULL(queue->head);
    TEST_ASSERT_NULL(queue->tail);

    queue_ll_free(queue);
}

void test_queue_ll_enqueue(void)
{
    struct queue_ll *queue = queue_ll_init();

    queue_ll_enqueue(queue, 4);
    queue_ll_enqueue(queue, 9);

    TEST_ASSERT_EQUAL(4, queue->head->data);
    TEST_ASSERT_EQUAL(9, queue->tail->data);

    queue_ll_free(queue);
}

void test_queue_ll_dequeue(void)
{
    struct queue_ll *queue = queue_ll_init();

    queue_ll_enqueue(queue, 3);
    queue_ll_enqueue(queue, 13);

    TEST_ASSERT_EQUAL(3, queue_ll_dequeue(queue));
    TEST_ASSERT_EQUAL(13, queue_ll_dequeue(queue));

    queue_ll_free(queue);
}

void test_queue_ll_empty(void)
{
    struct queue_ll *queue = queue_ll_init();
    TEST_ASSERT_EQUAL(1, queue_ll_empty(queue));

    queue_ll_enqueue(queue, 7);
    TEST_ASSERT_EQUAL(0, queue_ll_empty(queue));

    queue_ll_free(queue);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_queue_ll_init);
    RUN_TEST(test_queue_ll_enqueue);
    RUN_TEST(test_queue_ll_dequeue);
    RUN_TEST(test_queue_ll_empty);
    return UNITY_END();
}
