#include <iostream>

//Selection Sort

void selectionSort(int arr[], int n);
long long selectionSortWithCnt(int arr[], int n);

//Insertion Sort

void insertionSort(int arr[], int n);
long long insertionSortWithCnt(int arr[], int n);

// BubbleSort

void bubbleSort(int arr[], int n);
long long bubbleSortWithCnt(int arr[], int n);

// Shaker Sort

void shakerSort(int arr[], int n);
long long shakerSortWithCnt(int arr[], int n);

// Shell Sort

void shellSort(int arr[], int n);
long long shellSortWithCnt(int arr[], int n);

// Heap Sort

void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
long long heapifyWithCnt(int arr[], int n, int i);
long long heapSortWithCnt(int arr[], int n);

//Merge Sort

void mergeSort(int arr[], int n);
long long mergeSortWithCnt(int arr[], int n);

//Quick Sort

void swap(int &a, int &b);
void quickSort(int arr[], int left, int right);
long long quickSortWithCnt(int arr[], int left, int right);

//Counting Sort

void countingSort(int arr[], int n);
long long countingSortWithCnt(int arr[], int n);

//Radix Sort

void radixSort(int arr[], int n);
long long radixSortWithCnt(int arr[], int n);

//Flash Sort

void flashSort(int arr[], int n);
long long flashSortWithCnt(int arr[], int n);