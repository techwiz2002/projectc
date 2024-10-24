Project id: Group Project C  
Project Name: Permutations of numbers
Programmer: [Jada Isable]
Date: October 20, 2024

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Swap function
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

// Reverse function
void reverse(vector<int>& a, int i, int j) {
    while (i < j) {
        swap(a[i], a[j]);
        i++;
        j--;
    }
}

// next_permutation function for generating next lexicographical permutation
bool next_permutation(vector<int>& a) {
    for (int i = a.size() - 1; i > 0; i--) {
        if (a[i - 1] < a[i]) {
            int j = a.size() - 1;
            while (a[i - 1] > a[j]) {
                j--;
            }
            swap(a[i - 1], a[j]);
            reverse(a, i, a.size() - 1);
            return true;
        }
    }
    return false;
}

// Function to print a permutation of a string based on a given index permutation
void print_permutation(const string& s, const vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        cout << s[a[i]];
    }
    cout << endl;
}

int main() {
    string s = "eat";  // The input string
    int n = s.length();
    
    // Initialize the index vector [0, 1, 2, ..., n-1]
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }

    // Print the initial permutation
    print_permutation(s, a);

    // Generate and print all the permutations of the indices
    while (next_permutation(a)) {
        print_permutation(s, a);
    }

    return 0;
}
