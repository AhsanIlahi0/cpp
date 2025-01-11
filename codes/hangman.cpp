#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// Function to display the hangman
void displayHangman(int incorrectGuesses) {
    switch (incorrectGuesses) {
    case 0:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 1:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 2:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << "  |   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 3:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 4:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|\\  |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 5:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|\\  |" << endl;
        cout << " /    |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 6:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|\\  |" << endl;
        cout << " / \\  |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    }
}

// Function to initialize the secret word
string getRandomWord() {
    string words[] = {"hangman", "programming", "cplusplus", "developer", "openai", "challenge"};
    int randomIndex = rand() % (sizeof(words) / sizeof(words[0]));
    return words[randomIndex];
}

// Function to display the current state of the word with correctly guessed letters
void displayWord(const string& secretWord, const string& guessedLetters) {
    for (char letter : secretWord) {
        if (guessedLetters.find(letter) != string::npos) {
            cout << letter << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

int main() {
    
    srand(time(0));

    string secretWord = getRandomWord();
    string guessedLetters;
    int incorrectGuesses = 0;
    const int maxIncorrectGuesses = 6;

    cout << "Welcome to Hangman!" << endl;

    while (incorrectGuesses < maxIncorrectGuesses) {
        cout << endl;   
        displayHangman(incorrectGuesses);
        cout << "Guessed letters: " << guessedLetters << endl;
        displayWord(secretWord, guessedLetters);

        cout << "Guess a letter: ";
        char guess;
        cin >> guess;
        guess = tolower(guess);

        if (guessedLetters.find(guess) != string::npos) {
            cout << "You already guessed that letter. Try again." << endl;
            continue;
        }

        guessedLetters += guess;

        if (secretWord.find(guess) == string::npos) {
            cout << "Incorrect guess." << endl;
            incorrectGuesses++;
        } else {
            cout << "Correct guess!" << endl;
        }

        // Check if the player has guessed all letters
        bool allLettersGuessed = true;
        for (char letter : secretWord) {
            if (guessedLetters.find(letter) == string::npos) {
                allLettersGuessed = false;
                break;
            }
        }

        if (allLettersGuessed) {
            cout << "Congratulations! You guessed the word: " << secretWord << endl;
            break;
        }
    }

    if (incorrectGuesses == maxIncorrectGuesses) {
        cout << endl;
        displayHangman(incorrectGuesses);
        cout << "Sorry, you ran out of attempts. The correct word was: " << secretWord << endl;
    }

    return 0;
}
