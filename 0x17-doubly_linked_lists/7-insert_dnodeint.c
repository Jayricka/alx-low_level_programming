#include "lists.h"
#include <stdlib.h>

/**
* insert_dnodeint_at_index - Inserts a new node at a given position
* @h: A double pointer to the head of the list.
* @idx: The index where the new node should be inserted.
* @n: The data value of the new node.
*
* Return: The address of the new node, or NULL if it failed to add the node.
*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *new_node, *current = *h;
unsigned int i;

/* Handle case for inserting at index 0 */
if (idx == 0)
return (add_dnodeint(h, n));

/* Find the node at index - 1 */
for (i = 0; i < idx - 1 && current != NULL; i++)
current = current->next;

/* If current is NULL, the index is out of range */
if (current == NULL)
return (NULL);

/* Create the new node and set its values */
new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->prev = current;
new_node->next = current->next;

/* Update the next node's prev pointer */
if (current->next != NULL)
current->next->prev = new_node;

current->next = new_node;

return (new_node);
}
