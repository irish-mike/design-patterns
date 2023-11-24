#include "Sort.h"
#include <array>

void Sort::bubbleSort(int array[], int length)
{

	for (size_t i = 0; i < length; i++)
	{
		bool swapped = false;

		for (size_t j = 1; j < length - i; j++) {
			if (array[j - 1] > array[j]) {
				swap(array[j - 1], array[j]);
				swapped = true;
			}
		}

		if (!swapped) break;
	}
}

void Sort::selectionSort(int array[], int length)
{
	for (size_t i = 0; i < length -1; i++)
	{
		int min_index = i;

		for (size_t j = i+1; j < length; j++)
		{
			if (array[j] > array[min_index]) {
				min_index = j;
			}
		}

		if (min_index != i) {
			swap(array[i], array[min_index]);
		}
		
	}
}

void Sort::insertionSort(int array[], int length)
{

	for (size_t i = 1; i < length; i++)
	{
		int current = array[i];
		int index = i - 1;
		while (index >= 0 && current < array[index])
		{
			array[index + 1] = array[index];
			index--;
		}
		array[index +1] = current;
	}

}

void Sort::mergeSort(int array[], int length)
{
	if (length < 2) return;

	int middle_index = length / 2;

	int* left = new int[middle_index];
	int* right = new int[length - middle_index];

	copy(array, left, 0, middle_index);
	copy(array, right, middle_index, length);

	mergeSort(left, middle_index);
	mergeSort(right, length - middle_index);

	merge(left, middle_index, right, length-middle_index, array);
	delete[] left;
	delete[] right;
}

void Sort::copy(int source[], int dest[], int start, int length)
{
	for (int i = 0; i < length; ++i) {
		dest[i] = source[start + i];
	}
}

void Sort::merge(int left[], int left_size, int right[], int right_size, int merged[]) {

	int i{ 0 }, j{ 0 }, k{ 0 };

	while (i < left_size && j < right_size) {
		if (left[i] <= right[j]) {
			merged[k++] = left[i++];
		}
		else {
			merged[k++] = right[j++];
		}
	}

	while (i < left_size) {
		merged[k++] = left[i++];
	}

	while (j < right_size) {
		merged[k++] = right[j++];
	}

}

void Sort::swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}



