#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Perform the Hoare partition scheme.
 * @array: The array to partition.
 * @size: The size of the array.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 *
 * Return: The final partition index.
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[low];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return j;

		swap_ints(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * hoare_sort - Implement the quicksort algorithm using the Hoare partition scheme.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 */
void hoare_sort(int *array, size_t size, int low, int high)
{
	int partition;

	if (low < high)
	{
		partition = hoare_partition(array, size, low, high);
		hoare_sort(array, size, low, partition);
		hoare_sort(array, size, partition + 1, high);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}

