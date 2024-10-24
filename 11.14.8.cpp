#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Enum to represent the state of the DiskMover
enum State { BEFORE_LARGEST, LARGEST, AFTER_LARGEST, DONE };

class DiskMover {
public:
    // Constructor for DiskMover with number of disks, source peg, and target peg
    DiskMover(int num_disks, int source, int target)
        : num_disks(num_disks), source(source), target(target), state(BEFORE_LARGEST) {
        if (num_disks > 1) {
            int other = 6 - source - target; // Other peg is the one not in use (source + target + other = 6)
            helper_mover_before = make_unique<DiskMover>(num_disks - 1, source, other);
            helper_mover_after = make_unique<DiskMover>(num_disks - 1, other, target);
        }
    }

    // Check if there are more moves to generate
    bool has_more_moves() {
        return state != DONE;
    }

    // Generate the next move as a string
    string next_move() {
        switch (state) {
            case BEFORE_LARGEST:
                if (helper_mover_before->has_more_moves()) {
                    return helper_mover_before->next_move();
                } else {
                    state = LARGEST;  // Move to the next state to move the largest disk
                }
                // Fall through to the next case

            case LARGEST:
                state = AFTER_LARGEST;  // After moving the largest, go to the after state
                return "Move disk " + to_string(num_disks) + " from peg " + to_string(source) + " to peg " + to_string(target);

            case AFTER_LARGEST:
                if (helper_mover_after->has_more_moves()) {
                    return helper_mover_after->next_move();
                } else {
                    state = DONE;  // All moves are done
                }
                // Fall through to DONE

            case DONE:
                return "";  // No more moves
        }
        return "";  // Default case, though it shouldn't be hit
    }

private:
    int num_disks;                          // Number of disks to move
    int source;                             // Source peg
    int target;                             // Target peg
    State state;                            // Current state of the mover
    unique_ptr<DiskMover> helper_mover_before; // Helper to move d-1 disks before the largest disk
    unique_ptr<DiskMover> helper_mover_after;  // Helper to move d-1 disks after the largest disk
};

// Example usage
int main() {
    int num_disks = 5;
    int source = 1;
    int target = 3;

    DiskMover mover(num_disks, source, target);
    
    while (mover.has_more_moves()) {
        cout << mover.next_move() << endl;
    }

    return 0;
}
