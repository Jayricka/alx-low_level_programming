#include <stdio.h>
#include <stdlib.h>

/**
* binary_search - Searches for a value in an array using binary search.
* @array: A pointer to the first element of the array.
* @size: The number of elements in the array.
* @value: The value to search for.
*
* Return: If the value is not present or the array is NULL, return -1.
* Otherwise, return the index where the value is located.
*/
int binary_search(int *array, size_t size, int value)
{
int left = 0;
int right = size - 1;
int i;

if (array == NULL)
return (-1);

while (left <= right)
{
int mid = left + (right - left) / 2;

printf("Searching in array: ");
for (i = left; i <= right; i++)
{
printf("%d", array[i]);
if (i < right)
printf(", ");
}
printf("\n");

if (array[mid] == value)
return (mid);

if (array[mid] < value)
left = mid + 1;
else
right = mid - 1;
}

return (-1);
}
