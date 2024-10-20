#include <iostream>
#include <algorithm> // For transform and equal
#include <string>
using namespace std;

int main() {
    string secretWord = "magic";  // Wizard's secret word
    string guess;
    int attempts = 5;  // Limit on the number of attempts

    cout << "Welcome to the Wizard's Word Challenge!" << endl;
    cout << "You have " << attempts << " attempts to guess the secret word." << endl;

    // Convert secretWord to lowercase (in case you want case-insensitive comparison)
    transform(secretWord.begin(), secretWord.end(), secretWord.begin(), ::tolower);

    while (attempts > 0) {
        cout << "\nEnter your guess: ";
        cin >> guess;

        // Convert the guessed word to lowercase for case-insensitive comparison
        transform(guess.begin(), guess.end(), guess.begin(), ::tolower);

        if (guess == secretWord) {
            cout << "Congratulations! You guessed the correct word: " << secretWord << endl;
            break;
        } else {
            attempts--;
            cout << "Incorrect guess. Attempts remaining: " << attempts << endl;
        }
    }

    if (attempts == 0) {
        cout << "\nYou've used all your attempts! The secret word was: " << secretWord << endl;
    }

    return 0;
}
