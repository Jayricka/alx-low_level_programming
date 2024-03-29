#include "lists.h"
#include <stdlib.h>

/**
* delete_dnodeint_at_index - Deletes the node at the specified index
*                            of a doubly linked list.
* @head: A double pointer to the head of the list.
* @index: The index of the node to delete.
*
* Return: 1 if succeeded, -1 if it failed.
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *current, *temp;
unsigned int i;

if (head == NULL || *head == NULL)
return (-1);

current = *head;

if (index == 0)
{
*head = current->next;
if (current->next != NULL)
current->next->prev = NULL;
free(current);
return (1);
}

for (i = 0; i < index && current != NULL; i++)
current = current->next;

if (current == NULL)
return (-1);

if (current->next == NULL)
{
current->prev->next = NULL;
free(current);
return (1);
}

temp = current->prev;
temp->next = current->next;
current->next->prev = temp;
free(current);

return (1);
}
