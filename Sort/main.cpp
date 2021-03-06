#include <iostream>
#include <vector>
#include "quickSort.h"
#include "mergeSort.h"
#include "radixSort.h"
#include "insertionSort.h"
using namespace std;

int main()
{
    int i = 0;
    int temp = 0;
    int size = 0;
    vector<int> arr;

    // quick sort part
    // finish
    cout << "Quick Sort:" << endl;
    cin >> size;
    while (i < size)
    {
        cin >> temp;
        arr.push_back(temp);
        i++;
    }
    quickSort(arr, 0, arr.size() - 1);

    cout << endl;

    // merge sort part
    // finish
    cout << "Merge Sort:" << endl;
    arr.clear();
    i = 0;
    cin >> size;
    
    while (i < size)
    {
        cin >> temp;
        arr.push_back(temp);
        i++;
    }
    
    mergeSort(arr, 0, size - 1);

    cout << endl;
    // Radix Sort part
    // finish
    cout << "Radix Sort:" << endl;
    arr.clear();
    cin >> size;
    i = 0;
    while (i < size)
    {
        cin >> temp;
        arr.push_back(temp);
        i++;
    }
    radixSort(arr, size);
    
    cout << endl;
    // insertion sort part
    // finish
    cout << "Insertion Sort:" << endl;
    arr.clear();
    i = 0;
    cin >> size;
    while (i < size)
    {
        cin >> temp;
        arr.push_back(temp);
        i++;
    }
    insertionSort(arr, size);

    return 0;
}
