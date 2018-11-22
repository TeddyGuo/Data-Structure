#include <iostream>
#include <vector>
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
    }
}

void merge(vector<int>& arr, int begin, int mid, int end)
{
    vector<int> L(arr.begin() + begin, arr.begin() + mid + 1);
    vector<int> R(arr.begin() + mid + 1, arr.begin() + end + 1);
    int i = 0, j = 0, index = begin;

    L.insert(L.end(), 1000); R.insert(R.end(), 1000);

    while (index <= end)
    {
        if (L[i] < R[j])
        {
            arr[index] = L[i];
            i++;
        }
        else
        {
            arr[index] = R[j];
            j++;
        }
        index++;
    }

    // print out single element in L and R
    if (L.size() == 2)
    {
        cout << L[0] << endl;
    }
    if (R.size() == 2)
    {
        cout << R[0] << endl;
    }
    // print out
    for (int k = begin; k < end; k++)
    {
        cout << arr[k] << " ";
    }
    cout << arr[end] << endl;
}