#include "sort.h"
#include <stdio.h>

/**
 *_swap - swaps two array elements
 *@a: first element.
 *@b: second element.
 */
void _swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 *partition - divides array into sub-arrays for sorting operation.
 *@low: lower bound of the array to be sorted
 *@hi: upper bound.
 *@array: array to sort.
 *@size: size of the array.
 *Return: position that divides the two sub-arrays.
 */
int partition(int *array, int low, int hi, size_t size)
{

	int pivot = array[hi];
	int i = (low - 1), j;


	for (j = low; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			_swap(&array[i], &array[j]);
		}
	}

	_swap(&array[i + 1], &array[hi]);
	print_array(array, size);

	return (i + 1);
}

/**
 *_quicksort - performs the sort recursively
 *@low: lower bound.
 *@array: array to sort.
 *@hi: upper bound.
 *@size: size of the array.
 */
void _quicksort(int *array, int low, int hi, size_t size)
{
	if (low < hi)
	{
		int loc = partition(array, low, hi, size);

		_quicksort(array, (loc + 1), hi, size);
		_quicksort(array, low, (loc - 1), size);
	}
}

/**
 *quick_sort - function to call the quick sort algorithm
 *@array: array to sort.
 *@size: size of the array.
 */
void quick_sort(int *array, size_t size)
{
	int low = 0, hi = ((int)size - 1);

	if (!array || size < 2)
		return;

	_quicksort(array, low, hi, size);


}
