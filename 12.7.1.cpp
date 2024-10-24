//Project id : Group Project C7
//Project Name : Algorithm for finding the median
//Programmer : [Aleksandr Nurtdinov]
//Tester: [Jada Isable]
//Date : October 22, 2024
//Problem: 12.17.1
//Description : The task is to implement an algorithm for finding the median. 
// Instead of sorting the entire array to find the median, the algorithm works faster, finding the desired element in O(n) time.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> 

using namespace std;

int partition(vector<int>& arr, int a, int b, int pivot) // array partition function
{
    int pivotValue = arr[pivot];
    swap(arr[pivot], arr[b - 1]);
    int storeIndex = a;
    for (int i = a; i < b - 1; ++i) 
    {
        if (arr[i] < pivotValue) 
        {
            swap(arr[i], arr[storeIndex]);
            ++storeIndex;
        }
    }
    swap(arr[storeIndex], arr[b - 1]);
    return storeIndex;
}

int select(vector<int>& arr, int k, int a, int b) // function that implements a recursive algorithm for finding the k-th smallest element.
{
    if (a == b - 1) 
        return arr[a]; 

    int pivot = a + rand() % (b - a); // random selection of a pivot element
    int pivotIndex = partition(arr, a, b, pivot);
    int n1 = pivotIndex - a;

    if (k < n1) 
    {
        return select(arr, k, a, pivotIndex); // search on the left side
    }
    else if (k > n1) 
    {
        return select(arr, k - n1 - 1, pivotIndex + 1, b); // search on the right side
    }
    else 
    {
        return arr[pivotIndex];
    }
}

int main() 
{
    vector<int> arr = { 9, 2, 8, 4, 7, 6, 3, 1, 5 };
    int n = arr.size();
    int median = select(arr, n / 2, 0, n);

    cout << "Median: " << median << endl;
    return 0;
}
