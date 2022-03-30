/**
 * @file turnstile.h
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief An finite state machine representing a basic turnstile
 * @version 0.1
 * @date 2022-03-30
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

enum state { LOCKED, UNLOCKED };

void step(enum state *const state, const char *input);
