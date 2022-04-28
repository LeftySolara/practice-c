#include "binary_search.h"

/**
 * @brief Finds an item in a sorted array
 *
 * @param arr The array to search
 * @param target The value to search for
 * @param arr_size The size of the array
 * @return int The index of the found item, or -1 if the item is not found
 */
int binary_search(int *arr, int target, size_t arr_size)
{
    int min = 0;
    int max = arr_size - 1;
    int guess;

    while (min <= max) {
        guess = (min + max) / 2;
        if (arr[guess] < target) {
            min = guess + 1;
        }
        else if (arr[guess] > target) {
            max = guess - 1;
        }
        else {
            return guess;
        }
    }
    return -1;
}