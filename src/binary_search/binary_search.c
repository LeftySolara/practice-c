/**
 * @file binary_search.c
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief Binary search implementations with and without recursion
 * @version 0.1
 * @date 2022-08-28
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

#include <stddef.h>

#include "binary_search.h"

/**
 * @brief Find the index of an item in an array
 *
 * @param arr The array to search
 * @param target The item to search for
 * @param arr_size The size of the array
 *
 * @return int The index of the found item, or -1 if not found
 */
int binary_search(int *arr, int target, size_t arr_size)
{
    int left = 0;
    int right = arr_size - 1;
    int midpoint;

    while (left <= right) {
        midpoint = (left + right) / 2;
        if (arr[midpoint] > target) {
            right = midpoint - 1;
        }
        else if (arr[midpoint] < target) {
            left = midpoint + 1;
        }
        else {
            return midpoint;
        }
    }
    return -1;
}

/**
 * @brief Recursively find the index of an item in an array
 *
 * @param arr The array to search
 * @param target The item to search for
 * @param low The minimum index to check
 * @param high The maximum index to check
 *
 * @return int The index of the found item, or -1 if not found
 */
int binary_search_recursive(int *arr, int target, size_t low, size_t high)
{
    if (low > high) {
        return -1;
    }

    size_t midpoint = (low + high) / 2;

    if (target == arr[midpoint]) {
        return midpoint;
    }

    if (arr[midpoint] > target) {
        return binary_search_recursive(arr, target, low, midpoint - 1);
    }
    else {
        return binary_search_recursive(arr, target, midpoint + 1, high);
    }
}
