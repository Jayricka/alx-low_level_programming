#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: The hash table to add or update the key/value to.
 * @key: The key. Must not be an empty string.
 * @value: The value associated with the key. Must be duplicated.
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node = NULL, *tmp = NULL;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	/* Check if key already exists, update value */
	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = strdup(value);
			return (1);
		}
		tmp = tmp->next;
	}

	/* Create new node */
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}

	/* Add new node at the beginning of the list */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
