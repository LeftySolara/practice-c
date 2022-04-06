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

void nop(const char *input);

void unlock(const char *input);

void lock(const char *input);

struct branch {
    enum state const next_state;
    void (*action)(const char *);
};

void step(enum state *const state, const char *input);
