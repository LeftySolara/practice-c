/**
 * @file hash_table.c
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief A basic hash table implementation
 * @version 0.1
 * @date 2022-08-27
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

/**
 * @brief Create a new hash table of size max_size
 *
 * @param mex_size The size of the hash table
 * @return struct hash_table* A pointer to the new hash table struct
 */
struct hash_table *hash_table_new(size_t size)
{
    struct hash_table *table = malloc(sizeof(*table));
    if (!table) {
        return NULL;
    }

    table->data = malloc(sizeof(struct key_value_pair) * size);
    if (!table->data) {
        free(table);
        return NULL;
    }
    for (int i = 0; i < size; ++i) {
        table->data[i] = NULL;
    }

    table->size = size;

    return table;
}

/**
 * @brief Free memory used by a hash table
 *
 * @param table The table to free
 */
void hash_table_free(struct hash_table *table)
{
    for (int i = 0; i < table->size; ++i) {
        if (table->data[i]) {
            free(table->data[i]->key);
            free(table->data[i]);
        }
    }
    free(table->data);
    free(table);
}

/**
 * @brief Create a hash from a key
 *
 * @param key The key to create a hash from
 * @param table_size The size of the hash table
 * @return size_t The value of the hashed key
 */
size_t hash(const char *key, size_t table_size)
{
    /* djb2 algorithm */
    unsigned long hash = 5381;
    int c;

    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % table_size;
}

/**
 * @brief Add a new key-value pair to a hash table
 *
 * @param table The table to add the key-value pair to
 * @param key The key to add to the table
 * @param value The value to assign to the given key
 */
void hash_table_add(struct hash_table *table, char *key, int value)
{
    struct key_value_pair *pair = malloc(sizeof(*pair));
    if (!pair) {
        return;
    }

    pair->key = malloc(sizeof(char) * (strlen(key) + 1));
    strcpy(pair->key, key);
    pair->value = value;

    size_t index = hash(key, table->size);
    table->data[index] = pair;
}

/**
 * @brief Check whether a key exists in a hash table
 *
 * @param table The table to check
 * @param key The key to search for
 * @return int 0 if the key does not exist, or 1 otherwise
 */
int hash_table_key_exists(struct hash_table *table, const char *key)
{
    size_t index = hash(key, table->size);
    if (!table->data[index] || !table->data[index]->key) {
        return 0;
    }

    int key_match = strcmp(key, table->data[index]->key);
    return (key_match == 0);
}

/**
 * @brief Retrieve a value from a hash table based on a key
 *
 * @param table The table to check
 * @param key The key in the table to search for
 * @return int The value of the found item
 */
int hash_table_get(struct hash_table *table, const char *key)
{
    if (!hash_table_key_exists(table, key)) {
        return INT_MIN;
    }
    size_t index = hash(key, table->size);
    return table->data[index]->value;
}

/**
 * @brief Remove a key-value pair from a hash table
 *
 * @param table The table to remove the pair from
 * @param key The key to remove
 */
void hash_table_remove(struct hash_table *table, const char *key)
{
    if (!hash_table_key_exists(table, key)) {
        return;
    }

    int index = hash(key, table->size);
    free(table->data[index]->key);
    free(table->data[index]);
    table->data[index] = NULL;
}
