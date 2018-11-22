#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
using namespace std;

void quickSort(vector<int>&, int, int);
int partition(vector<int>&, int, int); // return pivot index

#endif