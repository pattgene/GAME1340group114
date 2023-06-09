//game1.cpp
#include <iostream>
#include <fstream>
#include <random>
#include "game1.h"

using namespace std;

int game1(string playername) {
    int level, starting_num, ending_num, guess_num, num_guesses = 0;
    int points = 0;
    bool correct_guess = false;
    int num_wrong_guesses = 0;
    const int max_wrong_guesses = 6;
    const string hangman_parts = "O|/\\\\/";
    bool odd_or_even_hint_given = false;

    //Game Instruction
    cout << "Welcome, " << playername << ", to Game 1." <<endl;
    cout << "THIS GAME IS GUESSING A NUMBER!!!!! " <<endl;
    cout << "You have 6 chances to guess the correct number depending on the difficulty selected to gain points!"<<endl;
    cout << "For easy difficulty, the number will be between 0 and 10."<<endl;
    cout << "For medium difficulty, the number will be between 0 and 20."<<endl;
    cout << "For hard difficulty, the number will be between 0 and 30."<<endl;
    cout << "You will earn 3, 4, and 5 points respectively for each difficulties."<<endl;
    cout << "What are you waiting for, better get guessing!"<<endl;

    // Choose difficulty level
    cout << "Choose the difficulty level (1 - Easy, 2 - Normal, 3 - Hard): ";
    while (!(cin >> level) || level < 1 || level > 3) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, try again (1 - Easy, 2 - Normal, 3 - Hard): ";
    }
    

    // Set starting and ending numbers based on the difficulty level
    switch (level) {
    case 1:
        starting_num = 0;
        ending_num = 10;
        break;
    case 2:
        starting_num = 0;
        ending_num = 20;
        break;
    case 3:
        starting_num = 0;
        ending_num = 30;
        break;
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        guesses[num_guesses] = guess_num;
        num_guesses++;

        if (guess_num == random_num) {
            correct_guess = true;
        } else {
            num_wrong_guesses++;
            cout << "Incorrect guess. " <<endl;

            // Print the hangman
            cout << "  _____" << endl;
            cout << "  |   |" << endl;
            cout << "  |   " << (num_wrong_guesses > 0 ? hangman_parts.substr(0, 1) : " ") << endl;
            cout << "  |  " << (num_wrong_guesses > 1 ? hangman_parts.substr(2, 1) : " ") << (num_wrong_guesses > 2 ? hangman_parts.substr(1, 1) : " ") << (num_wrong_guesses > 3 ? hangman_parts.substr(3, 1) : " ")<< endl;
            cout << "  |  " << (num_wrong_guesses > 4 ? hangman_parts.substr(4, 1) : " ") << " " << (num_wrong_guesses > 5 ? hangman_parts.substr(5, 1) : " ") << endl;
            cout << "__|__" << endl;

            //Give hint after 2 wrong guesses
            // Give hint if two wrong guesses have been made and no hint has been given yet
            if (num_wrong_guesses == 2 && !odd_or_even_hint_given) {
                cout << "Hint: The number is " << (random_num % 2 == 0 ? "even." : "odd.") << endl;
                cout << "You still have some chances!!! " <<endl;
                odd_or_even_hint_given = true;
            }
        }
    }

    // Print the results of the game
    if (correct_guess) {
        cout << "Congratulations!!! (づ˶> ᵕ < ︎˶)づ❤︎ You guessed the number in " << num_guesses << " tries." << endl;
        num_wrong_guesses += 1;// to make it print correct guess in result
        
        // Reward player with points respective to difficulty level
        if (level == 1) {
            points = 3;
        } else if (level == 2) {
            points = 4;
        } else if (level == 3) {
            points = 5;
        }
    } else {
        cout << "Sorry, you didn't guess the number. The number was " << random_num << "." << endl;
        cout << "(˵•̀⤙•́˵)૭"<<endl;
    }

    delete[] guesses;
    if (correct_guess){
        return points;
    }
    else{
        return 0;
    }
}
