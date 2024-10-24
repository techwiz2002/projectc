//Project id : Group Project C7
//Project Name : Implementation of merge_sort function without recursion
//Programmer : [Aleksandr Nurtdinov]
//Tester: [Jada Isable]
//Date : October 22, 2024
//Problem: 12.17.7
//Description : This task implements the merge_sort function without recursion, where the array size is an arbitrary number.
// 
//


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void merge(vector<int>& arr, int left, int mid, int right) // Defining a function merge that merges two sorted subarrays
{
    int n1 = mid - left + 1;  
    int n2 = right - mid;     

    vector<int> leftArr(n1), rightArr(n2);


    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        rightArr[i] = arr[mid + 1 + i];


    int i = 0, j = 0, k = left;

 
    while (i < n1 && j < n2) 
    {
        if (leftArr[i] <= rightArr[j]) 
        {
            arr[k] = leftArr[i];
            i++;
        }
        else 
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) 
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr) // the merge_sort function without recursion
{
    int n = arr.size();

    
    for (int currSize = 1; currSize <= n - 1; currSize *= 2) 
    {
        
        for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * currSize) 
        {
            
            int mid = min(leftStart + currSize - 1, n - 1);
            int rightEnd = min(leftStart + 2 * currSize - 1, n - 1);

            
            merge(arr, leftStart, mid, rightEnd);
        }
    }
}

int main() 
{
    vector<int> arr = { 15, 7, 6, 12, 1, 9 };

    cout << "Given array is: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    mergeSort(arr);

    cout << "Sorted array is: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}

