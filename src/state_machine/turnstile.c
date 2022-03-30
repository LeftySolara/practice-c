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

void step(enum state *const state, const char *input)
{
    switch (*state) {
        case LOCKED:
            if (strcmp(input, "coin") == 0) {
                printf("Unlocking...");
                *state = UNLOCKED;
            }
            break;
        case UNLOCKED:
            if (strcmp(input, "push") == 0) {
                printf("Locking...");
                *state = LOCKED;
            }
            break;
    }
}
