#include <linux/limits.h>

#include "../src/hello_world/hello_world.h"
#include "../unity/src/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_hello_world(void)
{
    TEST_ASSERT_EQUAL(hello(), 1);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_hello_world);
    return UNITY_END();
}
