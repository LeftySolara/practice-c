/**
 * @file turnstile.c
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief An finite state machine representing a basic turnstile
 * @version 0.1
 * @date 2022-03-30
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

#include <stdio.h>
#include <string.h>

#include "turnstile.h"

struct branch const transitions[2][2] = {
    // coin		             // push        Inputs/States
    {{UNLOCKED, &unlock}, {LOCKED, &nop}},  // locked
    {{UNLOCKED,    &nop}, {LOCKED, &lock}}  // unlocked
};

void nop(const char *input)
{
}

void unlock(const char *input)
{
    printf("Unlocking...");
}

void lock(const char *input)
{
    printf("Locking...");
}

void step(enum state *const state, const char *input)
{
    int const row = (*state == LOCKED) ? 0 : 1;
    int const column = strcmp(input, "coin") == 0 ? 0 : 1;
    struct branch const *const branch = &transitions[row][column];
    *state = branch->next_state;
    branch->action(input);
}
