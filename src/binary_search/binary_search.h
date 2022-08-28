/**
 * @file binary_search.h
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief Binary search implementations with and without recursion
 * @version 0.1
 * @date 2022-08-28
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stddef.h>

/** Find the index of an item in an array */
int binary_search(int *arr, int target, size_t arr_size);

/** Recursively find the index of an item in an array */
int binary_search_recursive(int *arr, int target, size_t low, size_t high);

#endif /* BINARY_SEARCH_H */
