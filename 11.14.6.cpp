#include <iostream>
#include <cctype>  // For isalpha and tolower
#include <string>

using namespace std;

// Helper function to clean the string: remove non-letter characters and convert to lowercase
string clean_string(const string& s) {
    string cleaned;
    for (char c : s) {
        if (isalpha(c)) {
            cleaned += tolower(c);
        }
    }
    return cleaned;
}

// Recursive function to check if a string is a palindrome
bool is_palindrome(const string& s, int start, int end) {
    // Base case: if the string has zero or one character left, it's a palindrome
    if (start >= end) {
        return true;
    }
    
    // Recursive case: compare the first and last character, and recurse on the substring
    if (s[start] == s[end]) {
        return is_palindrome(s, start + 1, end - 1);
    } else {
        return false;
    }
}

int main() {
    string input = "Madam, I’m Adam!";
    
    // Clean the input string by removing non-letter characters and converting to lowercase
    string cleaned_input = clean_string(input);
    
    // Check if the cleaned string is a palindrome
    if (is_palindrome(cleaned_input, 0, cleaned_input.length() - 1)) {
        cout << "\"" << input << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << input << "\" is not a palindrome." << endl;
    }

    return 0;
}
