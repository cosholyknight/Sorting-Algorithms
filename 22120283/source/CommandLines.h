#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "DataGenerator.h"
#include "SortAlgorithms.h"

using namespace std;

void newQuickSort(int arr[], int n);
long long newQuickSortWithCnt(int arr[], int n);
double timeCounting(int arr[], int n, int iAlgo);
void commandProcess(int arr[], int n, int iAlgo, string opPara, std::ifstream &fi);
void commandOneAndThree(string algor, string givenInput, string opPara);
void commandTwo(string algor, string inputSize, string ipOrder, string opPara);
void compMode(int arr[], int n, int iAlgo1, int iAlgo2, std::ifstream &fi);
void commandFour(string givenAlgo1, string givenAlgo2, string inputFile);
void commandFive(string givenAlgo1, string givenAlgo2, string inputSize, string ipOrder);