#include "SortAlgorithms.h"

// Selection Sort
// https://deviot.vn/tutorials/c-co-ban.78025672/thuat-toan-sap-xep-lua-chon.80502462

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

long long selectionSortWithCnt(int arr[], int n) {
    long long cnt = 0;
    int i, j, minIndex, temp;
    for (i = 0; ++cnt && i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; ++cnt && j < n; j++) {
            if (++cnt && arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
    return cnt;
}

// Insertion Sort
// https://www.geeksforgeeks.org/insertion-sort/

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

long long insertionSortWithCnt(int arr[], int n) {
    int i, key, j;
    long long cnt = 0;
    for (i = 1; ++cnt && i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (++cnt && j >= 0 && ++cnt && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return cnt;
}

// BubbleSort
// https://viblo.asia/p/thuat-toan-sap-xep-noi-bot-bubble-sort-m68Z0exQlkG
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

long long bubbleSortWithCnt(int arr[], int n) {
    int i, j, temp;
    long long cnt = 0;
    for (i = 0; ++cnt && i < n - 1; i++) {
        for (j = 0; ++cnt && j < n - i - 1; j++) {
            if (++cnt && arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return cnt;
}

// Shaker Sort
// https://daynhauhoc.com/t/cau-truc-du-lieu-va-giai-thuat-giai-thuat-sap-xep-rung-lac-shaker-sort/126359
void shakerSort(int arr[], int n) {
    int left = 0, right = n - 1, temp, i;
    while (left <= right) {
        for (i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        right--;
        for (i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        }
        left++;
    }
}

long long shakerSortWithCnt(int arr[], int n) {
    int left = 0, right = n - 1, temp, i;
    long long cnt = 0;
    while (++cnt && left <= right) {
        for (i = left; ++cnt && i < right; i++) {
            if (++cnt && arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        right--;
        for (i = right; ++cnt && i > left; i--) {
            if (++cnt && arr[i] < arr[i - 1]) {
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        }
        left++;
    }
    return cnt;
}

// Shell Sort
// https://www.tutorialspoint.com/Shell-Sort

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

long long shellSortWithCnt(int arr[], int n) {
    long long cnt = 0;
    for (int gap = n / 2; ++cnt && gap > 0; gap /= 2) {
        for (int i = gap; ++cnt && i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; ++cnt && j >= gap && ++cnt && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    return cnt;
}

// Heap Sort
// https://www.geeksforgeeks.org/heap-sort/

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int temp;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

long long heapifyWithCnt(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;
    long long cnt = 0;

    if (++cnt && left < n && ++cnt && arr[left] > arr[largest]) {
        largest = left;
    }

    if (++cnt && right < n && ++cnt && arr[right] > arr[largest]) {
        largest = right;
    }

    if (++cnt && largest != i) {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        cnt += heapifyWithCnt(arr, n, largest);
    }
    return cnt;
}

long long heapSortWithCnt(int arr[], int n) {
    int temp;
    long long cnt = 0;
    for (int i = n / 2 - 1; ++cnt && i >= 0; i--) {
        cnt += heapifyWithCnt(arr, n, i);
    }
    for (int i = n - 1; ++cnt && i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        cnt += heapifyWithCnt(arr, i, 0);
    }
    return cnt;
}

// Merge Sort
// https://www.geeksforgeeks.org/merge-sort/

void mergeSort(int arr[], int n)
{
    if (n <= 1)
    {
        return;
    }

    int mid = n / 2;
    int *left = new int[mid];
    int *right = new int[n - mid];

    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }

    for (int i = mid; i < n; i++)
    {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, n - mid);

    int i = 0, j = 0, k = 0;

    while (i < mid && j < n - mid)
    {
        if (left[i] < right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }

    while (i < mid)
    {
        arr[k++] = left[i++];
    }

    while (j < n - mid)
    {
        arr[k++] = right[j++];
    }

    delete[] left;
    delete[] right;
}

long long mergeSortWithCnt(int arr[], int n)
{
    long long cnt = 0;

    if (++cnt && n <= 1)
    {
        return cnt;
    }

    int mid = n / 2;
    int *left = new int[mid];
    int *right = new int[n - mid];

    for (int i = 0; ++cnt && i < mid; i++)
    {
        left[i] = arr[i];
    }

    for (int i = mid; ++cnt && i < n; i++)
    {
        right[i - mid] = arr[i];
    }

    cnt += mergeSortWithCnt(left, mid);
    cnt += mergeSortWithCnt(right, n - mid);

    int i = 0, j = 0, k = 0;

    while (++cnt && i < mid && ++cnt && j < n - mid)
    {
        if (++cnt && left[i] < right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }

    while (++cnt && i < mid)
    {
        arr[k++] = left[i++];
    }

    while (++cnt && j < n - mid)
    {
        arr[k++] = right[j++];
    }

    delete[] left;
    delete[] right;

    return cnt;
}


// Quick Sort
// https://freetuts.net/thuat-toan-sap-xep-nhanh-quick-sort-2940.html

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(int arr[], int left, int right)
{
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    while (i <= j)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j)
    {
        quickSort(arr, left, j);
    }
    if (i < right)
    {
        quickSort(arr, i, right);
    }
}

long long quickSortWithCnt(int arr[], int left, int right)
{
    long long cnt = 0;
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    while (++cnt && i <= j)
    {
        while (++cnt && arr[i] < pivot)
        {
            i++;
        }
        while (++cnt && arr[j] > pivot)
        {
            j--;
        }
        if (++cnt && i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (++cnt && left < j)
    {
        cnt += quickSortWithCnt(arr, left, j);
    }
    if (++cnt && i < right)
    {
        cnt += quickSortWithCnt(arr, i, right);
    }
    return cnt;
}

// Counting Sort
// https://viblo.asia/p/sap-xep-bang-dem-phan-phoi-counting-sort-Qbq5Q63LKD8

void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int* count = (int*) malloc(sizeof(int) * (max + 1));
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

long long countingSortWithCnt(int arr[], int n) {
    long long cnt = 0;
    int max = arr[0];
    for (int i = 1; ++cnt && i < n; i++) {
        if (++cnt && arr[i] > max) {
            max = arr[i];
        }
    }
    int* count = (int*) malloc(sizeof(int) * (max + 1));
    for (int i = 0; ++cnt && i <= max; ++i) {
        count[i] = 0;
    }
    for (int i = 0; ++cnt && i < n; i++) {
        count[arr[i]]++;
    }
    int index = 0;
    for (int i = 0; ++cnt && i <= max; i++) {
        while (++cnt && count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
    return cnt;
}

// Radix Sort
// https://viblo.asia/p/tim-hieu-ve-radix-sort-va-cach-implement-thuat-toan-nay-trong-swift-E375zk0PKGW

void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        max = arr[i] > max ? arr[i] : max;
    }
    for (int exp = 1; max / exp > 0; exp *= 10) {
        int* output = (int*) malloc(sizeof(int) * n);
        int count[10] = {0};
        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
        free(output);
    }
}

long long radixSortWithCnt(int arr[], int n) {
    long long cnt = 0;
    int max = arr[0];
    for (int i = 1; ++cnt && i < n; i++) {
        ++cnt;
        max = arr[i] > max ? arr[i] : max;
    }
    for (int exp = 1; ++cnt && max / exp > 0; exp *= 10) {
        int* output = (int*) malloc(sizeof(int) * n);
        int count[10] = {0};
        for (int i = 0; ++cnt && i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }
        for (int i = 1; ++cnt && i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; ++cnt && i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        for (int i = 0; ++cnt && i < n; i++) {
            arr[i] = output[i];
        }
        free(output);
    }
    return cnt;
}

// Flash Sort
// https://www.w3resource.com/javascript-exercises/searching-and-sorting-algorithm/searching-and-sorting-algorithm-exercise-12.php


void flashSort(int arr[], int n) {
    if (n <= 1) return;
    int m = n * 0.43;
    if (m <= 2) m = 2;
    // int m = n;
    int* __L = new int[m];
    for (int i = 0; i < m; ++i)
        __L[i] = 0;
    int Mx = arr[0], Mn = arr[0];
    for (int i = 1; i < n; ++i) {
        if (Mx < arr[i]) Mx = arr[i];
        if (Mn > arr[i]) Mn = arr[i];
    }
    if (Mx == Mn)
        return;
    #define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
    for (int i = 0; i < n; ++i)
        ++__L[getK(arr[i])];
    for (int i = 1; i < m; ++i)
        __L[i] += __L[i - 1];
    int count = 0;
    int i = 0;
    while (count < n) {
        int k = getK(arr[i]);
        while (i >= __L[k]) 
            k = getK(arr[++i]);
        int z = arr[i];
        while (i != __L[k]) {
            k = getK(z);
            int y = arr[__L[k] - 1];
            arr[--__L[k]] = z;
            z = y;
            ++count;
        }
    }   
    for (int k = 1; k < m; ++k) {
        for (int i = __L[k] - 2; i >= __L[k - 1]; --i)
            if (arr[i] > arr[i + 1]) {
                int t = arr[i], j = i;
                while (t > arr[j + 1]) {arr[j] = arr[j + 1]; ++j;}
                arr[j] = t;
            }
    }
    delete[] __L;
}

long long flashSortWithCnt(int arr[], int n) {
    long long cnt = 0;
    if (++cnt && n <= 1) return cnt;
    int m = n * 0.43;
    if (++cnt && m <= 2) m = 2;
    // int m = n;
    int* __L = new int[m];
    for (int i = 0; ++cnt && i < m; ++i)
        __L[i] = 0;
    int Mx = arr[0], Mn = arr[0];
    for (int i = 1; ++cnt && i < n; ++i) {
        if (++cnt && Mx < arr[i]) Mx = arr[i];
        if (++cnt && Mn > arr[i]) Mn = arr[i];
    }
    if (++cnt && Mx == Mn)
        return cnt;
    #define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
    for (int i = 0; ++cnt && i < n; ++i)
        ++__L[getK(arr[i])];
    for (int i = 1; ++cnt && i < m; ++i)
        __L[i] += __L[i - 1];
    int count = 0;
    int i = 0;
    while (++cnt && count < n) {
        int k = getK(arr[i]);
        while (++cnt && i >= __L[k]) 
            k = getK(arr[++i]);
        int z = arr[i];
        while (++cnt && i != __L[k]) {
            k = getK(z);
            int y = arr[__L[k] - 1];
            arr[--__L[k]] = z;
            z = y;
            ++count;
        }
    }   
    for (int k = 1; ++cnt && k < m; ++k) {
        for (int i = __L[k] - 2; ++cnt && i >= __L[k - 1]; --i)
            if (++cnt && arr[i] > arr[i + 1]) {
                int t = arr[i], j = i;
                while (++cnt && t > arr[j + 1]) {
                    arr[j] = arr[j + 1];
                    ++j;
                }
                arr[j] = t;
            }
    }
    delete[] __L;
    return cnt;
}