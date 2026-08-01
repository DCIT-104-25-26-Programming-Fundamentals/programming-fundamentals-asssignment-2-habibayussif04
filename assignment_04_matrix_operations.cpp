// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 10;

// Helper function to input matrix elements from the user
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, const string& name) {
    cout << "\nEnter elements for Matrix " << name << " (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Helper function to print a matrix in a neatly aligned grid
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

// -----------------------------------------------------------------------------
// PART A — Transpose Function
// -----------------------------------------------------------------------------
void transposeMatrix(const int src[MAX_SIZE][MAX_SIZE], int rows, int cols, int dest[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            dest[j][i] = src[i][j];
        }
    }
}

// -----------------------------------------------------------------------------
// PART B — Addition Function
// -----------------------------------------------------------------------------
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// -----------------------------------------------------------------------------
// PART C — Multiplication Function
// -----------------------------------------------------------------------------
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int m, int n, int p, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            result[i][j] = 0; // Initialize cell
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[MAX_SIZE][MAX_SIZE];
    int B[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    // =========================================================================
    // PART A: Transpose
    // =========================================================================
    cout << "==========================================" << endl;
    cout << "PART A: MATRIX TRANSPOSE" << endl;
    cout << "==========================================" << endl;
    int rA, cA;
    cout << "Enter number of rows: ";
    cin >> rA;
    cout << "Enter number of columns: ";
    cin >> cA;

    inputMatrix(A, rA, cA, "A");

    cout << "\nOriginal Matrix A:" << endl;
    printMatrix(A, rA, cA);

    transposeMatrix(A, rA, cA, result);

    cout << "\nTransposed Matrix (Dimensions: " << cA << "x" << rA << "):" << endl;
    printMatrix(result, cA, rA);

    // =========================================================================
    // PART B: Addition
    // =========================================================================
    cout << "\n==========================================" << endl;
    cout << "PART B: MATRIX ADDITION" << endl;
    cout << "==========================================" << endl;
    int rB, cB;
    cout << "Enter number of rows for both matrices: ";
    cin >> rB;
    cout << "Enter number of columns for both matrices: ";
    cin >> cB;

    inputMatrix(A, rB, cB, "A");
    inputMatrix(B, rB, cB, "B");

    addMatrices(A, B, rB, cB, result);

    cout << "\nResult of Matrix A + B:" << endl;
    printMatrix(result, rB, cB);

    // =========================================================================
    // PART C: Multiplication
    // =========================================================================
    cout << "\n==========================================" << endl;
    cout << "PART C: MATRIX MULTIPLICATION" << endl;
    cout << "==========================================" << endl;
    int m, n, p;
    cout << "Enter rows for Matrix A (M): ";
    cin >> m;
    cout << "Enter cols for Matrix A / rows for Matrix B (N): ";
    cin >> n;
    cout << "Enter cols for Matrix B (P): ";
    cin >> p;

    inputMatrix(A, m, n, "A");
    inputMatrix(B, n, p, "B");

    multiplyMatrices(A, B, m, n, p, result);

    cout << "\nResult of Matrix A x B (Dimensions: " << m << "x" << p << "):" << endl;
    printMatrix(result, m, p);

    return 0;
}
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

