
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row, int n) {
    // All queens have been placed
    if (row == n)
        return true;

    // Try placing a queen in each column
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;  // Place queen

            if (solveNQueens(board, row + 1, n))
                return true;

            board[row][col] = 0;  // Backtrack
        }
    }

    return false;
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    if (n <= 0) {
        cout << "N must be positive." << endl;
        return 0;
    }

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNQueens(board, 0, n)) {
        cout << "Solution:\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists for N = " << n << endl;
    }

    return 0;
}
