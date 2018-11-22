#include <iostream>
#include <vector>
#include <algorithm>
#include "radixSort.h"

using namespace std;

int findLargestNum(vector<int>& arr)
{
    int max = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

void radixSort(vector<int>& arr, int N)
{
    int large = findLargestNum(arr);
    vector<int> semiSort(N, 0);
    int digit = 1;
    int i = 0;

    while (large / digit > 0)
    {
        vector<int> bucket(10, 0);

        for (i = 0; i < N; i++)
            bucket[(arr[i] / digit) % 10]++;
        
        for (i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];

        for (i = N - 1; i >= 0; i--)
            semiSort[--bucket[(arr[i] / digit) % 10]] = arr[i];

        for (i = 0; i < N; i++)
            arr[i] = semiSort[i];

        digit *= 10;

        // print out
        for (i = 0; i < arr.size() - 1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << arr[i] << endl;
    }
}