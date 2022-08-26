/**
 * @file queue_arr.h
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief A simple queue implementation using an array
 * @version 0.1
 * @date 2022-08-26
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

struct queue_arr {
    int *data;
    int head;
    int tail;
    int size;
    int capacity;
};

struct queue_arr *queue_arr_new(int capacity);

void queue_arr_free(struct queue_arr *queue);

void queue_arr_enqueue(struct queue_arr *queue, int value);

int queue_arr_dequeue(struct queue_arr *queue);
