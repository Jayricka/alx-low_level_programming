#include "lists.h"
#include <stdlib.h>

/**
* get_dnodeint_at_index - Returns the nth node of a doubly linked list.
* @head: A pointer to the head of the list.
* @index: The index of the node to retrieve.
*
* Return: The nth node of the list, or NULL if it doesn't exist.
*/

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
dlistint_t *current = head;
unsigned int count = 0;

while (current != NULL)
{
if (count == index)
return (current);

count++;
current = current->next;
}

return (NULL);
}
