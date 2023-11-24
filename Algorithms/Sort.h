#pragma once
class Sort
{
public:
	static void bubbleSort(int array[], int length);
	static void selectionSort(int array[], int length);
	static void insertionSort(int array[], int length);

	static void mergeSort(int array[], int length);

	static void swap(int& a, int& b);
	static void copy(int source[], int dest[],int start, int length);
	static void merge(int left[], int left_size, int right[], int right_size, int merged[]);
};

