Project id: Group Project C  
Project Name: Phone numbers and pin
Programmer: [Jada Isable]
Date: October 20, 2024

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Mapping of digits to corresponding letters
unordered_map<char, string> phoneMap = {
    {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
};

// Recursive function to generate all possible spellings
vector<string> generateSpellings(string number) {
    // Base case: if number is empty, return a vector with an empty string
    if (number.empty()) {
        return {""};
    }

    // Get the letters corresponding to the first digit
    char digit = number[0];
    string letters = phoneMap[digit];

    // Recursively generate spellings for the remaining digits
    vector<string> subSpellings = generateSpellings(number.substr(1));

    // Combine each letter with each of the sub_spellings
    vector<string> results;
    for (char letter : letters) {
        for (const string& subSpelling : subSpellings) {
            results.push_back(letter + subSpelling);
        }
    }

    return results;
}

int main() {
    string number = "2633"; // Example input
    vector<string> spellings = generateSpellings(number);

    // Print all generated spellings
    for (const string& spelling : spellings) {
        cout << spelling << endl;
    }

    return 0;
}
