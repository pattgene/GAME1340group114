//game1.cpp
#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int main() {
    int starting_num, ending_num, guess_num, num_guesses = 0;
    bool correct_guess = false;
    int num_wrong_guesses = 0;
    const int max_wrong_guesses = 6;
    const string hangman_parts = "O|/\\\\/";

    // Prompt the user to enter the starting and ending numbers
    cout << "Enter the starting number: ";
    cin >> starting_num;
    cout << "Enter the ending number: ";
    cin >> ending_num;

    // Check if the user input for starting_num and ending_num is valid
    while (starting_num > ending_num) {
        cout << "Invalid input, try again!!." << endl;
        cout << "Enter the starting number: ";
        cin >> starting_num;
        cout << "Enter the ending number: ";
        cin >> ending_num;
    }

    // Generate a random number between starting_num and ending_num
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(starting_num, ending_num);
    int random_num = dist(gen);

    // Prompt the user to guess the number
    int* guesses = new int[max_wrong_guesses];
    while (!correct_guess && num_wrong_guesses < max_wrong_guesses) {
        cout << "Guess the number: ";
        cin >> guess_num;
        guesses[num_guesses] = guess_num;
        num_guesses++;

        if (guess_num == random_num) {
            correct_guess = true;
        } else {
            num_wrong_guesses++;
            cout << "Incorrect guess. ";
            if (guess_num < random_num) {
                cout << "The number is higher." << endl;
            } else {
                cout << "The number is lower." << endl;
            }

            // Print the hangman
            cout << "  _____" << endl;
            cout << "  |   |" << endl;
            cout << "  |   " << (num_wrong_guesses > 0 ? hangman_parts.substr(0, 1) : " ") << endl;
            cout << "  |  " << (num_wrong_guesses > 1 ? hangman_parts.substr(2, 1) : " ") << (num_wrong_guesses > 2 ? hangman_parts.substr(1, 1) : " ") << (num_wrong_guesses > 3 ? hangman_parts.substr(3, 1) : " ") << endl;
            cout << "  |  " << (num_wrong_guesses > 4 ? hangman_parts.substr(4, 1) : " ") << " " << (num_wrong_guesses > 5 ? hangman_parts.substr(5, 1) : " ") << endl;
            cout << "__|__" << endl;
        }
    }

    // Print the results of the game
    if (correct_guess) {
        cout << "Congratulations! You guessed the number in " << num_guesses << " tries." << endl;
        cout << "You can see your game result in gameresult.txt file."<<endl;
    } else {
        cout << "Sorry, you didn't guess the number. The number was " << random_num << "." << endl;
        cout << "You can see your game result in gameresult.txt file."<<endl;
    }

    // Save the results of the game to a file
    ofstream file("game_results.txt");
    if (!file) {
        cout << "Error: Could not open game_results.txt for writing." << endl;
        return 1;
    }
    file << "Starting number: " << starting_num << endl;
    file << "Ending number: " << ending_num << endl;
    file << "Random number: " << random_num << endl; // <-- added semicolon here
    file.close();
    delete[] guesses;
    return 0;

}
