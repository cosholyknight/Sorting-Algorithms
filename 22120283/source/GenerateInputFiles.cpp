#include "DataGenerator.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string dataOrder[4] = {"randomized_data", "sorted_data", "reverse_sorted_data", "nearly_sorted_data"};
    int dataSize[6] = {10000, 30000, 50000, 100000, 300000, 500000};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            std::ofstream ofile((string) "../input/" + dataOrder[i] + (string) "/" + dataOrder[i]
            + "_" + to_string(dataSize[j]) + (string) ".txt", std::ios::app);
            int* arr = new int[dataSize[j]];
            ofile << dataSize[j] << "\n";
            GenerateData(arr, dataSize[j], i);
            for (int k = 0; k < dataSize[j]; k++) {
                ofile << arr[k] << " ";
            }
            ofile.close();
            delete[] arr;
        }
    }
}