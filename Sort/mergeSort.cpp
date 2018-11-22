#include <iostream>
#include <vector>
#include <cstdlib>
#include "mergeSort.h"

using namespace std;

void mergeSort(vector<int>& arr, int begin, int end)
{
    if (begin < end)
    {
        int mid = (begin + end) / 2;
        mergeSort(arr, begin, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, begin, mid, end);

        // print out
        for (int k = begin; k < end; k++)
        {
            cout << arr[k] << " ";
        }
        cout << arr[end] << endl;
    }
    else
    {
        // print out the single element
        cout << arr[end] << endl;
    }
}

void merge(vector<int>& arr, int begin, int mid, int end)
{
    int i = begin, j = mid + 1, index = 0;
    int *temp = (int*)calloc(end - begin + 1, sizeof(int));

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp[index] = arr[i++];
        }
        else
        {
            temp[index] = arr[j++];
        }
        index++;
    }
    while (i <= mid)
    {
        temp[index++] = arr[i++];
    }
    while (j <= end)
    {
        temp[index++] = arr[j++];
    }
    for (i = begin; i <= end; i++)
    {
        arr[i] = temp[i - begin];
    }

    free(temp);
}