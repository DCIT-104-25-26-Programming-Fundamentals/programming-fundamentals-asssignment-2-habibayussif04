// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
#include <iostream>
using namespace std;

// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
void printFibonacci(int n) {
    if (n <= 0) {
        cout << "Error: Number of terms must be a positive integer." << endl;
        return;
    }

    cout << "Fibonacci sequence: ";

    long long first = 0, second = 1;

    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            cout << first;
        } else if (i == 2) {
            cout << " " << second;
        } else {
            long long next = first + second;
            cout << " " << next;
            first = second;
            second = next;
        }
    }
    cout << endl;
}

// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
bool isFibonacci(long long num) {
    if (num < 0) {
        return false;
    }

    // Special base cases for 0 and 1
    if (num == 0 || num == 1) {
        return true;
    }

    long long first = 0;
    long long second = 1;
    long long next = first + second;

    // Generate terms iteratively until we reach or exceed the target number
    while (next < num) {
        first = second;
        second = next;
        next = first + second;
    }

    return (next == num);
}

int main() {
    // Part A Test
    cout << "--- PART A ---" << endl;
    int n;
    cout << "How many terms? ";
    cin >> n;
    printFibonacci(n);

    cout << endl;

    // Part B Test
    cout << "--- PART B ---" << endl;
    long long target;
    cout << "Enter a number to check: ";
    cin >> target;

    if (isFibonacci(target)) {
        cout << target << " is a Fibonacci number." << endl;
    } else {
        cout << target << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}
// =============================================================================

#include <iostream>
using namespace std;

