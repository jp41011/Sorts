#ifndef SORTS_H
#define SORTS_H
#include <math.h>
#include <stdlib.h>
#include <vector>

using std::vector;

// swaps values 
void xchg(short&, short&);

void selectionSort(vector<short>&);

void insertionSort(vector<short>&);

void shellSort(vector<short>&);

void mergeSort(vector<short>&);
void mergeSortHelper(vector<short>&, short, short);
void merge(vector<short>&, short, short, short);

void quickSort(vector<short>&);
void quick_sort(vector<short>&, short, short);
short random_partition(vector<short>&, short, short);
short partition(vector<short>&, short, short);

#endif