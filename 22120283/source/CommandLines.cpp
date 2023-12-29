#include "CommandLines.h"

using namespace std;

typedef void(*func)(int[], int);
typedef long long(*funccnt)(int[], int);
string outputParameter[] = {"-time", "-comp", "-both"};
string inputOrder[] = {"-rand", "-sorted", "-rev", "-nsorted"};
string algo[11] = {"selection-sort", "insertion-sort", "bubble-sort", "shaker-sort", "shell-sort", "heap-sort", "merge-sort", "quick-sort", "counting-sort", "radix-sort", "flash-sort"};
string sortAlgoName[11] = {"Selection Sort", "Insertion Sort", "Bubble Sort", "Shaker Sort", "Shell Sort", "Heap Sort", "Merge Sort", "Quick Sort", "Counting Sort", "Radix Sort", "Flash Sort"};
func sortAlgo[11] = {selectionSort, insertionSort, bubbleSort, shakerSort, shellSort, heapSort, mergeSort, newQuickSort, countingSort, radixSort, flashSort};
funccnt sortAlgoWithCnt[11] = {selectionSortWithCnt, insertionSortWithCnt, bubbleSortWithCnt, shakerSortWithCnt, shellSortWithCnt, heapSortWithCnt, mergeSortWithCnt, newQuickSortWithCnt, countingSortWithCnt, radixSortWithCnt, flashSortWithCnt};
string dataOrder[4] = {"randomized_data", "sorted_data", "reverse_sorted_data", "nearly_sorted_data"};
int dataSize[6] = {10000, 30000, 50000, 100000, 300000, 500000};

void newQuickSort(int arr[], int n) {
    quickSort(arr, 0, n - 1);
}

long long newQuickSortWithCnt(int arr[], int n) {
    return quickSortWithCnt(arr, 0, n - 1);
}

double timeCounting(int arr[], int n, int iAlgo) {
    clock_t start = clock();
    sortAlgo[iAlgo](arr, n);
    clock_t stop = clock();
    double duration = (double) (stop - start) / CLOCKS_PER_SEC;
    return duration;
}

void commandProcess(int arr[], int n, int iAlgo, string opPara, std::ifstream &fi) {
    std::cout << "Running time (if required): ";
    if (opPara == outputParameter[0] || opPara == outputParameter[2]) {
        std::cout << timeCounting(arr, n, iAlgo) << " seconds" << "\n";
    }
    else {
        std::cout << "not required.\n";
    }

    std::cout << "Comparisons (if required): ";
    if (opPara == outputParameter[1] || opPara == outputParameter[2]) {
        for (int i = 0; i < n; i++) {
            fi >> arr[i];
        }
        std::cout << sortAlgoWithCnt[iAlgo](arr, n) << "\n";
    }
    else {
        std::cout << "not required.\n";
    }
}

void commandOneAndThree(string algor, string givenInput, string opPara)
{
    // identify algorithms
    int iAlgo = 0;
    for (; iAlgo < 11; iAlgo++) {
        if (algor == algo[iAlgo]) {
            break;
        }
    }

    // command 3
    if (givenInput[givenInput.size() - 1] >= '0' && givenInput[givenInput.size() - 1] <= '9') {
        int nSize = atoi(givenInput.c_str());
        int *arr = new int[nSize];

        std::ofstream *dataFile = new std::ofstream[4];

        std::cout << "ALGORITHM MODE\n";
        std::cout << "Algorithm: " << algor << "\n";
        std::cout << "Input size: " << nSize << "\n";
        std::cout << "\n";

        for (int i = 0; i < 4; i++) {
            dataFile[i].open("../input/input_" + std::to_string(i + 1) + ".txt");
        }

        for (int i = 0; i < 4; i++) {
            std::cout << "Input order: ";
            if (i == 0) {
                std::cout << "Randomized\n";
            }
            else if (i == 1) {
                std::cout << "Sorted\n";
            }
            else if (i == 2) {
                std::cout << "Reversed\n";
            }
            else if (i == 3) {
                std::cout << "Nearly sorted\n";
            }
            std::cout << "------------------------------\n";

            GenerateData(arr, nSize, i);

            dataFile[i] << nSize << "\n";
            for (int j = 0; j < nSize; j++) {
                dataFile[i] << arr[j] << " ";
            }

            std::ifstream fi("../input/input_" + std::to_string(i + 1) + ".txt");

            commandProcess(arr, nSize, iAlgo, opPara, fi);

            fi.close();
        }

        for (int i = 0; i < 4; i++) {
            dataFile[i].close();
        }

        delete[] dataFile;
        delete[] arr;
    }
    else { // command 1
        std::ifstream fi(givenInput);

        int nSize;
        fi >> nSize;

        int *a = new int[nSize];

        std::cout << "ALGORITHM MODE\n";
        std::cout << "Algorithm: " << algor << "\n";
        std::cout << "Input file: " << givenInput << "\n";
        std::cout << "Input size: " << nSize << "\n";
        std::cout << "------------------------------\n";

        for (int i = 0; i < nSize; i++) {
            fi >> a[i];
        }

        fi.clear();
        fi.seekg(0, std::ios::beg);

        commandProcess(a, nSize, iAlgo, opPara, fi);

        std::ofstream fo("../output/output.txt");
        fo << nSize << "\n";
        for (int i = 0; i < nSize; i++) {
            fo << a[i] << " ";
        }

        fi.close();
        fo.close();
        delete[] a;
    }
}

void commandTwo(string algor, string inputSize, string ipOrder, string opPara) {
    // identify algorithms
    int iAlgo = 0;
    for (; iAlgo < 11; iAlgo++) {
        if (algor == algo[iAlgo]) {
            break;
        }
    }

    // identify order
    int iOrder = 0;
    for (; iOrder < 4; iOrder++) {
        if (ipOrder == inputOrder[iOrder]) {
            break;
        }
    }
    // generate data
    int nSize = atoi(inputSize.c_str());
    int *arr = new int[nSize];

    std::cout << "ALGORITHM MODE\n";
    std::cout << "Algorithm: " << algor << "\n";
    std::cout << "Input size: " << nSize << "\n";
    std::cout << "Input order: " << ipOrder << "\n";
    std::cout << "------------------------------\n";

    GenerateData(arr, nSize, iOrder);
    std::ofstream finp("../input/input.txt");

    finp << nSize << "\n";
    for (int i = 0; i < nSize; i++) {
        finp << arr[i] << " ";
    }
    finp.close();

    std::ifstream fi("../input/input.txt");

    for (int i = 0; i < nSize; i++) {
        fi >> arr[i];
    }

    fi.clear();
    fi.seekg(0, std::ios::beg);

    commandProcess(arr, nSize, iAlgo, opPara, fi);

    fi.close();

    std::ofstream fo("../output/output.txt");

    fo << nSize << "\n";
    for (int i = 0; i < nSize; i++) {
        fo << arr[i] << " ";
    }

    fo.close();

    delete[] arr;
}

void compMode(int arr[], int n, int iAlgo1, int iAlgo2, std::ifstream &fi)
{
    std::cout << "Running time: " << timeCounting(arr, n, iAlgo1) << " seconds | ";
    for (int i = 0; i < n; i++)
    {
        fi >> arr[i];
    }
    fi.clear();
    fi.seekg(0, std::ios::beg);

    std::cout << timeCounting(arr, n, iAlgo2) << " seconds\n";

    for (int i = 0; i < n; i++)
    {
        fi >> arr[i];
    }
    fi.clear();
    fi.seekg(0, std::ios::beg);

    std::cout << "Comparisons: " << sortAlgoWithCnt[iAlgo1](arr, n) << " | ";
    for (int i = 0; i < n; i++)
    {
        fi >> arr[i];
    }
    fi.clear();
    fi.seekg(0, std::ios::beg);

    std::cout << sortAlgoWithCnt[iAlgo2](arr, n) << "\n";
}

void commandFour(string givenAlgo1, string givenAlgo2, string inputFile)
{
    std::cout << "COMPARISON MODE\n";
    std::cout << "Algorithm: " << givenAlgo1 << " | " << givenAlgo2 << "\n";
    std::cout << "Input file: " << inputFile << "\n";

    std::ifstream fi(inputFile);

    int iAlgo1 = 0, iAlgo2 = 0;
    for (; iAlgo1 < 11; iAlgo1++) {
        if (givenAlgo1 == algo[iAlgo1]) {
            break;
        }
    }
    for (; iAlgo2 < 11; iAlgo2++) {
        if (givenAlgo2 == algo[iAlgo2]) {
            break;
        }
    }

    int nSize;
    fi >> nSize;
    std::cout << "Input size: " << nSize << "\n";
    std::cout << "------------------------------\n";

    int *a = new int[nSize];

    for (int i = 0; i < nSize; i++)
    {
        fi >> a[i];
    }

    fi.clear();
    fi.seekg(0, std::ios::beg);

    compMode(a, nSize, iAlgo1, iAlgo2, fi);

    fi.close();
    delete[] a;
}

void commandFive(string givenAlgo1, string givenAlgo2, string inputSize, string ipOrder)
{
    std::cout << "COMPARISON MODE\n";
    std::cout << "Algorithm: " << givenAlgo1 << " | " << givenAlgo2 << "\n";
    std::cout << "Input size: " << inputSize << "\n";
    std::cout << "Input order: " << inputOrder << "\n";

    int iAlgo1 = 0, iAlgo2 = 0;
    for (; iAlgo1 < 11; iAlgo1++)
    {
        if (givenAlgo1 == algo[iAlgo1])
        {
            break;
        }
    }
    for (; iAlgo2 < 11; iAlgo2++)
    {
        if (givenAlgo2 == algo[iAlgo2])
        {
            break;
        }
    }

    int iOrder = 0;
    for (; iOrder < 4; iOrder++) {
        if (ipOrder == inputOrder[iOrder]) {
            break;
        }
    }

    int nSize = atoi(inputSize.c_str());
    int *arr = new int[nSize];

    std::cout << "Input size: " << nSize << "\n";
    std::cout << "------------------------------\n";

    GenerateData(arr, nSize, iOrder);
    std::ofstream finp("../input/input.txt");

    finp << nSize << "\n";
    for (int i = 0; i < nSize; i++) {
        finp << arr[i] << " ";
    }
    finp.close();

    std::ifstream fi("../input/input.txt");

    for (int i = 0; i < nSize; i++) {
        fi >> arr[i];
    }

    fi.clear();
    fi.seekg(0, std::ios::beg);

    compMode(arr, nSize, iAlgo1, iAlgo2, fi);

    fi.close();
    delete[] arr;
}

