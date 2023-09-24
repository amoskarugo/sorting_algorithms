#include "sort.h"
#include <stdio.h>


/**
 *selection_sort - a function that implements selection sort algo
 *@array: array to sort
 *@size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	int i, j;

	if (!array || size == 1)
		return;

	for (i = 0; i < ((int)size - 1); i++)
	{
		int min = i;

		for (j = i + 1; j < ((int)size); j++)
		{
			if (array[min] > array[j])
				min = j;
		}

	if (min != i)
	{
		int temp = array[i];

		array[i] = array[min];
		array[min] = temp;
		print_array(array, size);
	}

	}
}

