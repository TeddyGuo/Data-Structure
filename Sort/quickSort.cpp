#include "quickSort.h"
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void quickSort(vector<int>& arr, int begin, int end)
{
    if (begin < end)
    {
        int loc = partition(arr, begin, end);
        quickSort(arr, begin, loc - 1);
        quickSort(arr, loc + 1, end);
    }
}

int partition(vector<int>& arr, int begin, int end)
{
    int left = begin, right = end, loc = begin, flag = 0;
    
    // Step 2: repeat Step 3 to 6 while flag = 0
    while (flag == 0)
    {
        // Step 3:
        while (arr[loc] <= arr[right] && loc != right)
        {
            right = right - 1;
        }
        // Step 4:
        if (loc == right)
            flag = 1;
        else if (arr[loc] > arr[right])
        {
            swap(arr[loc], arr[right]);
            loc = right;
        }
        // Step 5:
        if (flag == 0)
        {
            while (arr[loc] >= arr[left] && loc != left)
                left++;
            if (loc == left)
                flag = 1;
            else if (arr[loc] < arr[left])
            {
                swap(arr[loc], arr[left]);
                loc = left;
            }
        }
    }

    // print out
    for (int i = 0; i < arr.size() - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << arr[arr.size() - 1] << endl;

    return loc;
}