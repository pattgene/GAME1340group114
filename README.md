# GAME1340group114
HKU GAME Project 1340 G.114

Members
1. Cia Hannah Olivia - 3036037334
2. Susabda Joshua - 3036029739
3. Lie Warren Leander - 3036094306
4. Phurtivilai Patt - 3036085226

### MAIN

This is the central hub where players can access the different mini-games. The player starts with 10 points, and each spin of the wheel costs 2 points. The wheel can land on "Minus," "Plus," or one of the available mini-games. If it lands on "Minus," the player loses 2 points; if it lands on "Plus," the player wins 5 points. If it lands on a mini-game, the player can win more points based on their performance in the mini-game. The player can keep spinning the wheel as long as they have at least 2 points. The final score will be displayed on the scoreboard. Once a mini-game has been played, it cannot be played again in the same session.

### HANGMAN

In this variant of game, instead of guessing a word, the player is challenged with guessing a number. The game starts with an instruction that explains the rules and objectives of the game to the player. The player is then prompted to select a difficulty level, which determines the range of numbers that the hidden number will be selected from. The player has a limited number of guesses to correctly guess the number, and each incorrect guess results in a part of a hangman being drawn on the screen. The game also includes a hint system that provides a clue after two incorrect guesses have been made. The hint reveals whether the number is odd or even, which can help the player narrow down their guesses and increase their chances of success. At the end of the game, the player is awarded points based on the difficulty level.


### BLACKJACK

This game is played between the player and the dealer (the computer). The goal of the game is to get a hand that is as close to 21 as possible without going over. The game starts by shuffling a standard 52-card deck and dealing two cards each to the player and the dealer. The player's cards are displayed along with their current score. The player is then given the option to draw additional cards ("hit") or to stand with their current hand. Once the player has decided to stand, the dealer's hand is revealed, and additional cards are drawn for the dealer until their score is at least 17. The winner is then determined by comparing the scores of the player and the dealer. The game includes an Ace card, which can have a value of 1 or 11, depending on the current score of the player. If the player's current score is not over 10, Ace will be assigned as 11. However, if the player's current score is over 10, Ace will be assigned as 1. The game also includes a simple scoring system in which the value of each card is added to the player's score.

### SLOT MACHINE

The game is played by spinning three reels containing different fruits and a wild card. The player wins points if they get three of the same fruit OR 2 of the same fruit and a wild card. This will increase the chances of winning the game. The game starts by displaying a welcome message and instructions for the player. The player is then prompted to press ENTER to spin the reels. The game then displays an animation of the reels spinning, with each reel displaying a random fruit. The animation is updated with each iteration, and the player is prompted to press ENTER to continue spinning the reels. Once the animation is complete, the game displays the final results of the spin. 

### HOW TO PLAY
1. Download all files in your local computer.
2. Change directory to all these files.
3. type: make main in your command line
4. type: ./main in your command line

### ENJOY!!! 😉 


### CODE DESCRIPTION

#### Main.cpp
The player starts with 10 points and can spin a wheel that can land on one of three outcomes: "Minus", "Plus", or one of three mini-games: "Hangman", "BJ" or "Slot".

If the wheel lands on "Minus", the player loses 2 points. If it lands on "Plus", the player scores 5 points. If it lands on one of the mini-games, the player can play the mini-game, which can earn him additional points.

The player can spin the wheel as long as he has at least 2 points. Once the player runs out of points or stops playing, the game ends and the player's final score is displayed on a scoreboard.

The program includes functions for saving and displaying scores, as well as printing a loading animation and a colored box representing the wheel.

The program uses three separate game files ("game1.h", "game2.h" and "game3.h") to implement the mini-games.

The program also includes file input/output operations to save and load scores from a file called "scores.txt".

**save_score:** this function takes a reference to a vector of score structures, a string representing the player's name, and an integer representing the player's score. It searches the vector for a score structure with a matching name and updates the score if it is found. If no matching entry is found, a new score structure with the player's name and score is added to the vector.

**display_scores:** This function takes a reference to a vector of score structures and displays the contents of the vector on the console, showing the name and score of each entry.

**save_scores_to_file:** This function takes a reference to a vector of score structures and a string representing the name of a file. It opens the file in append mode and writes the contents of the vector to the file in CSV format (with each entry on a separate line and the name and score separated by a comma).

**load_scores_from_file:** This function takes a reference to a vector of score structures and a string representing the name of a file. It opens the file and reads its contents line by line. A new score structure is created for each line and added to the vector if it does not already contain a structure with the same name.

**print_loading:** This function takes a string parameter representing the name of a game and displays a loading animation on the console simulating the connection process to the game.

**print_box:** This function takes a vector of strings representing the options on the wheel and an integer indicating the index of the currently selected option. It prints a colored box on the console with an arrow pointing to the selected option.

**display_rules:** This function displays the rules of the casino game on the console.

**main:** This function is the entry point of the program and controls the flow of the game. It initializes the score vector, displays the rules and asks the player to enter his name. Then it starts a loop where the player can spin the wheel until he runs out of points or wants to end the game. When the wheel lands on a mini-game, the corresponding mini-game functions are called, the player's score is updated and displayed on the console. Finally, the score is saved in the game score vector and game score file and displayed on the scoreboard.


#### Game1.cpp
The purpose of the game is for the player to guess a randomly generated number within a certain range, with the number of attempts limited to 6.

**int game1(string playername)** function: This is the main function of the game. It takes a player name as input and returns the number of points earned by the player. It starts by displaying the game instructions, then prompts the player to choose the game difficulty level. Depending on the level chosen, the range of the random number to be guessed is set. A random number is then generated within this range. The player is prompted to guess the number, and feedback is given if the guess is correct or incorrect. If the guess is incorrect, a hangman image is displayed and a hint may be given. The game ends when the player either correctly guesses the number or runs out of attempts.

**switch (level)** statement: This statement sets the starting and ending numbers of the range for the random number to be guessed based on the level of difficulty chosen by the player.

**random_device rd;, mt19937 gen(rd());, uniform_int_distribution<> dist(starting_num, ending_num);, int random_num = dist(gen)**; code block: This code block generates a random number within the range of the starting and ending numbers set in the previous step. It uses a random device to seed the random number generator, and then generates a uniform distribution of integers within the specified range.

**while (!correct_guess && num_wrong_guesses < max_wrong_guesses)** loop: This loop continues until either the player correctly guesses the number or the player exhausts the maximum number of attempts allowed. If the player's guess is incorrect, the number of wrong guesses is incremented, and a hint may be given after the second wrong guess. Feedback is given after each guess by displaying either a congratulatory message or a hangman image.

**if (correct_guess)** statement: This statement is executed if the player correctly guesses the number. It congratulates the player, displays the number of attempts made, and awards points based on the level of difficulty chosen.

**delete[]** guesses; statement: This statement frees up the memory used by the dynamic array guesses.

In summary, the critical parts of the code include the main function, the switch statement that sets the range of the random number, the code block that generates the random number, the loop that controls the game and provides feedback, the statement that awards points to the player if the guess is correct, and the statement that frees up memory used by the dynamic array.

#### Game2.cpp
**void shuffle_deck(vector<Card>& deck);, void deal_card(vector<Card>& deck, vector<string>& hand, int& score);** In the Blackjack game, the cards are shuffled randomly at the beginning of each game using a random number generator. This ensures that each game is unique and provides an element of chance to the game.

The Blackjack game uses several data structures to store the game status, such as **hand **which uses the **card structure** to represent the hands of the player, and variables to store the current game state and scores. The **void display_hand(const string& label, const vector<string>& hand, int score);** function is used to display the player’s current hand. In addition, **player_score** and **dealer_score** variables are used to store the scores of player and dealer respectively. 

**int game2(std::string playername);** This is the main function of the game. The game is played like traditional Blackjack. However, we have added in a feature where the player can choose to "split" their hand if they receive two cards of the same rank. This creates two separate hands, and the player can then play each hand independently. This gives players a higher chance to win the game as they now have 2 different hands to play off. 

**bool can_split(vector<string>& hand);** This function returns either TRUE or FALSE depending on whether the hand can be split or not.

The code implements the card game Blackjack using C++. It includes functions for shuffling the deck, dealing cards, displaying the player's hand, determining whether the player can split their hand, and calculating the winner of the game. The game can be played with one or two hands, depending on whether the player chooses to split a pair of cards. The code also includes error handling for invalid user input and uses standard library functions for input/output and random number generation. Overall, the code demonstrates principles of game programming, including the use of data structures, randomization, and game logic.

  
#### Game3.cpp

**srand(time(0))** is used to seed the random number generator with the current time, so that the results of each spin are different.

A **dynamic array of 10 string pointers** called **emojis** is created using the new keyword. Each string pointer is assigned an emoji character that represents a slot machine symbol.

Three string variables called **slot1, slot2, and slot3** are created and assigned a random emoji character from the emojis array using the rand() function.

A **loop** is used to **animate the spinning of the reels** when the player presses the Enter key. The loop displays a spinning message and then updates the slot machine display by generating new random symbols using the **rand() function.**

After the loop completes, the final symbols are displayed in a slot machine format using ASCII art. If all three symbols are the same, the player **wins 4 points; **otherwise, the player **loses everything.**

**delete[] emojis** is used to free up the memory used by the emojis array.

The function returns either **4 points** or **0 points** depending on the outcome of the game.

In summary, the game3 function simulates a simple slot machine game using emojis as symbols. It uses random number generation, loops, and dynamic memory allocation to create a basic game that can be played from the command line.



