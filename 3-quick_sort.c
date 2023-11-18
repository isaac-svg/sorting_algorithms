#include "sort.h"

/**
* swap - swaps two integers
* @a: Pointer to the first integer
* @b: Pointer to the second integer
* Returns: void
*/
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
* partition - partition scheme.
* @array: The array to partition.
* @low: The low index of the partition.
* @high: The high index of the partition.
* @size: The size of the array.
* Returns: The partion index (int).
*/

int partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j;

for (j = low; j <= high - 1; j++)
{
if (array[j] <= pivot)
{
i++;
swap(&array[i], &array[j]);

print_array(array, size);
}
}
swap(&array[i + 1], &array[high]);
print_array(array, size);



return (i + 1);
}

/**
* quicksort - perform quicksort
* @array: The array to sort
* @low: The low index of the partition
* @high: The high index of the partition
* @size: The size of the array
* Returns: void
*/
void quicksort(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pi = partition(array, low, high, size);
quicksort(array, low, pi - 1, size);
quicksort(array, pi + 1, high, size);
}
}

/**
* quick_sort - Sorts an array of integers in ascending order
* @array: The array to sort
* @size: The size of the array
* Returns: void
*/
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quicksort(array, 0, size - 1, size);
}
