//Project id : Group Project C7
//Project Name : The radix sort algorithm sorts an array of n integers with d digits
//Programmer : [Aleksandr Nurtdinov]
//Tester: [Jada Isable]
//Date : October 22, 2024
//Problem: 12.17.4
//Description : The program takes an array of numbers from 0 to 999, sorts it using the Radix Sort method, and outputs the result. 
//Radix Sort works in O(d * n), where d is the number of digits (in this case, 3), and n is the number of elements in the array.
//


#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;


int getDigit(int num, int pos) // function that returns the digit of number num at position pos.
{
    return (num / static_cast<int>(pow(10, pos))) % 10;
}


void radixSort(vector<int>& arr, int maxDigits) // function to sort an array
{
    const int base = 10; 

    
    queue<int> line[base];

    
    for (int digitPos = 0; digitPos < maxDigits; ++digitPos) 
    {
        
        for (int num : arr) 
        {
            int digit = getDigit(num, digitPos);
            line[digit].push(num);
        }

        
        int index = 0;
        for (int i = 0; i < base; ++i) 
        {
            while (!line[i].empty())
            {
                arr[index++] = line[i].front();
                line[i].pop();
            }
        }
    }
}

int main() 
{
    vector<int> arr = { 156, 22, 778, 358, 14, 17, 2, 409 };
    int maxDigits = 3; 

    cout << "Original array: ";
    for (int num : arr) 
    {
        cout << num << " ";
    }
    cout << endl;

    radixSort(arr, maxDigits);

    cout << "Sorted array: ";
    for (int num : arr) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
