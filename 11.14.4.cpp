#include <iostream>
#include <string>
#include <memory>

using namespace std;

class PermutationIterator {
public:
    // Constructor that initializes the iterator with the input string
    PermutationIterator(string s) : str(s), current_pos(0), tail_iterator(nullptr) {
        if (!str.empty()) {
            update_tail_iterator();
        }
    }

    // Returns true if there are more permutations to generate
    bool has_more_permutations() {
        return current_pos < str.size();
    }

    // Returns the next permutation
    string next_permutation() {
        // If tail iterator has no more permutations, move to the next position
        if (!tail_iterator->has_more_permutations()) {
            current_pos++;
            if (current_pos < str.size()) {
                update_tail_iterator();  // Update to the next tail iterator
            }
        }
        
        // If we've exhausted all permutations
        if (current_pos >= str.size()) {
            return "";
        }

        // Get the next permutation from the tail iterator and prepend the current character
        return str[current_pos] + tail_iterator->next_permutation();
    }

private:
    string str;                          // The original string
    int current_pos;                     // The current character position
    unique_ptr<PermutationIterator> tail_iterator;  // Iterator for the remaining substring

    // Helper function to create a new tail iterator for the current position
    void update_tail_iterator() {
        // Create a substring that excludes the current character
        string tail_string = str.substr(0, current_pos) + str.substr(current_pos + 1);
        tail_iterator = make_unique<PermutationIterator>(tail_string);  // Create new iterator
    }
};

// Example usage
int main() {
    string input = "eat";
    PermutationIterator iter(input);

    while (iter.has_more_permutations()) {
        cout << iter.next_permutation() << endl;
    }

    return 0;
}
