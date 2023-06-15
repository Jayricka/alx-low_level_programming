#include "lists.h"
#include <stdlib.h>

/**
* sum_dlistint - sum of all the data values in a doubly linked list.
* @head: A pointer to the head of the list.
*
* Return: The sum of all the data values, or 0 if the list is empty.
*/
int sum_dlistint(dlistint_t *head)
{
dlistint_t *current = head;
int sum = 0;

while (current != NULL)
{
sum += current->n;
current = current->next;
}

return (sum);
}
