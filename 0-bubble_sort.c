#include "sort.h"
/**
 * bubble_sort - a function that implementsa bubble sort
 *                  algorithm
 * @array: an array of integers to sort
 * @size: size of the array
*/


void bubble_sort(int *array, size_t size)
{
	int swapped = 1;
	int i;

	if (!array || size < 2)
		return;

	while (swapped)
	{
		swapped = 0;
		for (i = 0; i < ((int)size - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				int temp = array[i];

				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
	}
}
