#include <iostream>
#include <vector>
#include <algorithm> // For find and count
using namespace std;

// Function to display the grid
void displayGrid(const vector<char>& grid) {
    for (int i = 0; i < 9; i++) {
        cout << grid[i] << " ";
        if ((i + 1) % 3 == 0) cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<char>& grid, char player) {
    vector<vector<int>> winPatterns = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}              // Diagonals
    };

    for (const auto& pattern : winPatterns) {
        if (grid[pattern[0]] == player && grid[pattern[1]] == player && grid[pattern[2]] == player) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<char> grid(9, '-'); // 3x3 grid initialized with '-'
    char currentPlayer = 'X';  // Starting player
    int moves = 0;

    while (moves < 9) {
        displayGrid(grid);
        int move;
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9 || grid[move - 1] != '-') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        grid[move - 1] = currentPlayer;
        moves++;

        // Check for a winner
        if (checkWin(grid, currentPlayer)) {
            displayGrid(grid);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    if (moves == 9) {
        displayGrid(grid);
        cout << "It's a draw!" << endl;
    }

    return 0;
}

