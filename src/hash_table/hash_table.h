/**
 * @file hash_table.h
 * @author Julianne Adams <julianne@julianneadams.info>
 * @brief A basic hash table implementation
 * @version 0.1
 * @date 2022-08-27
 *
 * @copyright Copyright (c) 2022 Julianne Adams
 *
 */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>

struct key_value_pair {
    char *key;
    int value;
};

struct hash_table {
    struct key_value_pair **data;
    size_t size;
};

struct hash_table *hash_table_new(size_t size);

void hash_table_free(struct hash_table *table);

size_t hash(const char *key, size_t table_size);

void hash_table_add(struct hash_table *table, char *key, int value);

int hash_table_key_exists(struct hash_table *table, const char *key);

int hash_table_get(struct hash_table *table, const char *key);

void hash_table_remove(struct hash_table *table, const char *key);

#endif /* HASH_TABLE_H */
