#include <iostream>
#include <vector>
#include <algorithm>  // For find
using namespace std;

// Function to check if the move is valid for a knight
bool isValidMove(int startX, int startY, int endX, int endY) {
    // All possible moves a knight can make (L-shaped moves)
    vector<pair<int, int>> knightMoves = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, // Vertical moves
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}  // Horizontal moves
    };

    // Calculate the move difference
    int moveX = endX - startX;
    int moveY = endY - startY;

    // Check if the move is in the list of valid knight moves
    return find(knightMoves.begin(), knightMoves.end(), make_pair(moveX, moveY)) != knightMoves.end();
}

int main() {
    int startX, startY, endX, endY;

    cout << "Welcome to Knight Console Chess!" << endl;
    cout << "You can move the knight by specifying the starting and ending positions." << endl;

    // Input for the starting position
    cout << "Enter the starting position of the knight (x y): ";
    cin >> startX >> startY;

    // Input for the target position
    cout << "Enter the target position of the knight (x y): ";
    cin >> endX >> endY;

    // Check if the move is valid
    if (isValidMove(startX, startY, endX, endY)) {
        cout << "Valid move!" << endl;
    } else {
        cout << "Invalid move. The knight cannot move there." << endl;
    }

    return 0;
}
