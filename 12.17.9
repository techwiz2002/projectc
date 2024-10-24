//Project id : Group Project C7
//Project Name : A comparison operator that compares strings.
//Programmer : [Aleksandr Nurtdinov]
//Tester: [Jada Isable]
//Date : October 22, 2024
//Problem: 12.17.9
//Description : Provide a comparison operator that can compare strings. Split each string into strings that do not contain digits or groups of digits. 
// Then compare the two strings by comparing the first non-digit groups as strings, the first groups of digits as integers, and so on.


#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <cctype>

using namespace std;


vector<string> splitString(const string& str) // Function to split a string into groups: numbers and non-numbers
{
    vector<string> parts;
    regex rgx("(\\d+|\\D+)");
    sregex_iterator it(str.begin(), str.end(), rgx);
    sregex_iterator end;
    while (it != end) 
    {
        parts.push_back((*it).str());
        ++it;
    }
    return parts;
}

bool customStringCompare(const string& s1, const string& s2) // Defining a function that compares two strings
{
    vector<string> parts1 = splitString(s1);
    vector<string> parts2 = splitString(s2);

    size_t n = std::min(parts1.size(), parts2.size());

    for (size_t i = 0; i < n; ++i) 
    {
        
        if (isdigit(parts1[i][0]) && isdigit(parts2[i][0])) 
        {
            int num1 = stoi(parts1[i]);
            int num2 = stoi(parts2[i]);
            if (num1 != num2) 
            {
                return num1 < num2;
            }
        }
        
        else if (parts1[i] != parts2[i]) 
        {
            return parts1[i] < parts2[i];
        }
    }

    return parts1.size() < parts2.size();
}

int main() 
{
    vector<string> files = { "sec3_14.txt", "sec10_1.txt", "sec7_7.txt", "sec3_10.txt", "sec6_12.txt" };

    sort(files.begin(), files.end());

    for (const auto& file : files) 
    {
        cout << file << endl;
    }

    return 0;
}
