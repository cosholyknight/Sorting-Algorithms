#include "Experiments.h"

typedef void(*func)(int[], int);
typedef long long(*funccnt)(int[], int);

//Overload function to match function pointer
void newQuickSort(int arr[], int n) {
    quickSort(arr, 0, n - 1);
}

long long newQuickSortWithCnt(int arr[], int n) {
    return quickSortWithCnt(arr, 0, n - 1);
}

void takeNote() {
    string sortAlgoName[11] = {"Selection Sort", "Insertion Sort", "Bubble Sort", "Shaker Sort", "Shell Sort", "Heap Sort", "Merge Sort", "Quick Sort", "Counting Sort", "Radix Sort", "Flash Sort"};
    func sortAlgo[11] = {selectionSort, insertionSort, bubbleSort, shakerSort, shellSort, heapSort, mergeSort, newQuickSort, countingSort, radixSort, flashSort};
    funccnt sortAlgoWithCnt[11] = {selectionSortWithCnt, insertionSortWithCnt, bubbleSortWithCnt, shakerSortWithCnt, shellSortWithCnt, heapSortWithCnt, mergeSortWithCnt, newQuickSortWithCnt, countingSortWithCnt, radixSortWithCnt, flashSortWithCnt};
    string dataOrder[4] = {"randomized_data", "sorted_data", "reverse_sorted_data", "nearly_sorted_data"};
    int dataSize[6] = {10000, 30000, 50000, 100000, 300000, 500000};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            int* arr = new int[dataSize[j]];
            std::ofstream ofile((string) "../take_note/" + dataOrder[i] + (string) "/" + dataOrder[i]
             + "_" + to_string(dataSize[j]) + (string) ".txt", std::ios::app);
            for (int k = 0; k < 11; k++) {
                GenerateData(arr, dataSize[j], i);
                clock_t start = clock();
                sortAlgo[k](arr, dataSize[j]);
                clock_t stop = clock();
                double duration = (double)(stop - start) / CLOCKS_PER_SEC;
                GenerateData(arr, dataSize[j], i);
                ofile << "--------------\n" << sortAlgoName[k] << "\nTime: " << std::fixed << std::setprecision(5) << duration
                << " seconds\nComparisons: " << sortAlgoWithCnt[k](arr, dataSize[j]) << "\n";
            }
            ofile.close();
            delete[] arr;
        }
    }
}