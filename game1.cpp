//game1.cpp
#include <iostream>
#include <fstream>
#include <random>
#include "game1.h"

using namespace std;

int game1() {
    int starting_num, ending_num, guess_num, num_guesses = 0;
    bool correct_guess = false;
    int num_wrong_guesses = 0;
    const int max_wrong_guesses = 6;
    const string hangman_parts = "O|/\\\\/";
    bool odd_or_even_hint_given = false;
    //Game Instruction
    cout << "Welcome you player to Game1: Guess for your life 🖤 " <<endl;
    cout << "You have 6 chances to guess a correct number to continue living your life!"<<endl;
    cout << "Each wrong number you will continue losing a part of your body to us Satan 😈"<<endl;

    // Prompt the user to enter the starting and ending numbers
    cout << "Enter the starting number: ";
    while (!(cin >> starting_num)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, try again: ";
    }
    cout << "Enter the ending number: ";
    while (!(cin >> ending_num)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, try again: ";
    }


    // Check if the user input for starting_num and ending_num is valid
    while (starting_num > ending_num) {
        cout << "Invalid input starting must be less than ending, try again, I know you can input a number. Just input a number!!!." << endl;
        cout << "Enter the starting number: ";
        while (!(cin >> starting_num)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, try again: ";
        }
        cout << "Enter the ending number: ";
        while (!(cin >> ending_num)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, try again: ";
        }
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
        cout << "Congratulations!!! 😀 You guessed the number in " << num_guesses << " tries." << endl;
        cout << "You can see your game result in gameresult.txt file."<<endl;
        num_wrong_guesses += 1;// to make it print correct guess in result
    } else {
        cout << "Sorry 😭, you didn't guess the number. The number was " << random_num << "." << endl;
        cout << "You can see your game result in game1_result.txt file."<<endl;
    }

    // Save the results of the game to a file
    ofstream file("game1_results.txt");
    if (!file) {
        cout << "Error: Could not open game1_results.txt for writing." << endl;
        //return 1;
    }
    if (correct_guess){
        file << "Congratulations!!! 😀 You won this game!!!" <<endl;
    }
    else{
        file << "Sorry, you loss!!! 😭"<<endl; 
    }
    file << "Starting number: " << starting_num << endl;
    file << "Ending number: " << ending_num << endl;
    file << "Your gusses: ";
    for (int i = 0; i < num_wrong_guesses; i++)
    {
        file << guesses[i] << ' ';
    }
    file << endl;
    file << "Random number: " << random_num << endl; 
    file.close();
    delete[] guesses;
    //return 0;
    if (correct_guess){
        return 1;
    }
    else{
        return 0;
    }

}
