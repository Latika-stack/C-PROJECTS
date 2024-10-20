#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
using namespace std;

int main() {
    srand(time(0));  // Seed for random number generation
    int hiddenNumber = rand() % 100 + 1;  // Random number between 1 and 100
    int guess;
    int attempts = 0;

    cout << "Welcome to the Hidden Number Hunt!" << endl;
    cout << "Guess the hidden number between 1 and 100." << endl;

    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > hiddenNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < hiddenNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You found the hidden number " << hiddenNumber << " in " << attempts << " attempts!" << endl;
            break;
        }
    }

    return 0;
}
