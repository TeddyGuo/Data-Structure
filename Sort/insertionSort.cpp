#include <iostream>
#include <vector>
#include "insertionSort.h"
using namespace std;

void insertionSort(vector<int>& arr, int N)
{
    int i = 1;
    while (i < N)
    {
        int temp = arr[i];
        int j = i - 1;
        while (temp <= arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
        i++;

        // print out
        for (int k = 0; k < arr.size() - 1; k++)
            cout << arr[k] << " ";
        cout << arr[arr.size() - 1] << endl;
    }
}