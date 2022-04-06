#include "../src/state_machine/turnstile.h"
#include "../unity/src/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_state_machine_step(void)
{
    enum state state = UNLOCKED;

    step(&state, "coin");
    TEST_ASSERT_EQUAL(state, UNLOCKED);

    step(&state, "push");
    TEST_ASSERT_EQUAL(state, LOCKED);

    step(&state, "push");
    TEST_ASSERT_EQUAL(state, LOCKED);

    step(&state, "coin");
    TEST_ASSERT_EQUAL(state, UNLOCKED);
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_state_machine_step);
    return UNITY_END();
}
