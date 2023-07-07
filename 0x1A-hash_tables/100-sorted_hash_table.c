#include "hash_tables.h"
#include <stdio.h>
#include <string.h>

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of new sorted hash table.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;
    unsigned long int i;

    ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return NULL;

    ht->size = size;
    ht->array = malloc(size * sizeof(shash_node_t *));
    if (ht->array == NULL)
    {
        free(ht);
        return NULL;
    }

    for (i = 0; i < size; i++)
        ht->array[i] = NULL;

    ht->shead = NULL;
    ht->stail = NULL;

    return ht;
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    shash_node_t *new_node, *current_node;

    if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
        return 0;

    index = key_index((const unsigned char *)key, ht->size);
    current_node = ht->array[index];

    while (current_node != NULL)
    {
        if (strcmp(current_node->key, key) == 0)
        {
            free(current_node->value);
            current_node->value = strdup(value);
            return 1;
        }
        current_node = current_node->next;
    }

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return 0;

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    /* Insert into sorted linked list */
    if (ht->shead == NULL)
    {
        ht->shead = new_node;
        ht->stail = new_node;
        new_node->sprev = NULL;
        new_node->snext = NULL;
    }
    else if (strcmp(key, ht->shead->key) < 0)
    {
        new_node->sprev = NULL;
        new_node->snext = ht->shead;
        ht->shead->sprev = new_node;
        ht->shead = new_node;
    }
    else
    {
        current_node = ht->shead;
        while (current_node->snext != NULL && strcmp(key, current_node->snext->key) >= 0)
            current_node = current_node->snext;

        new_node->sprev = current_node;
        new_node->snext = current_node->snext;

        if (current_node->snext != NULL)
            current_node->snext->sprev = new_node;
        else
            ht->stail = new_node;

        current_node->snext = new_node;
    }

    return 1;
}

/**
 * shash_table_get - Retrieve the value associated with a key in a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key is not found - NULL.
 *         Otherwise - the value associated with the key.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
    shash_node_t *current_node;

    if (ht == NULL || key == NULL || *key == '\0')
        return NULL;

    index = key_index((const unsigned char *)key, ht->size);
    current_node = ht->array[index];

    while (current_node != NULL)
    {
        if (strcmp(current_node->key, key) == 0)
            return current_node->value;

        current_node = current_node->next;
    }

    return NULL;
}

/**
 * shash_table_print - Prints a sorted hash table in order.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
    int first = 1;
    shash_node_t *node;

    if (ht == NULL)
        return;

    printf("{");
    node = ht->shead;
    while (node != NULL)
    {
        if (!first)
            printf(", ");
        printf("'%s': '%s'", node->key, node->value);
        first = 0;
        node = node->snext;
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    int first = 1;
    shash_node_t *node;

    if (ht == NULL)
        return;

    printf("{");
    node = ht->stail;
    while (node != NULL)
    {
        if (!first)
            printf(", ");
        printf("'%s': '%s'", node->key, node->value);
        first = 0;
        node = node->sprev;
    }
    printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
    unsigned long int i;
    shash_node_t *node, *next;

    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node != NULL)
        {
            next = node->next;
            free(node->key);
            free(node->value);
            free(node);
            node = next;
        }
    }

    free(ht->array);
    free(ht);
}
