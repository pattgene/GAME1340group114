#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game3() {
    cout << "Welcome to game 3!" << endl;
    cout << "If you get 3 of the same symbols, you will win 4 points back" << endl;
    cout << "Otherwise, you will lose everything" << endl;
    cout << "Press ENTER to generate the symbols! ";
    srand(time(0));
    string emojis[10] = {"🍎", "🍊", "🍇", "🍒", "🍓", "🍋", "🍉", "🍌", "🍑", "🍐"};
    string slot1 = emojis[rand() % 10];
    string slot2 = emojis[rand() % 10];
    string slot3 = emojis[rand() % 10];
    if (cin.get() == '\n') {
            cout << "┏━━━┳━━━┳━━━┓" << endl;
            cout << "┃ " << slot1 << "┃ " << slot2 << "┃ " << slot3 << "┃" << endl;
            cout << "┗━━━┻━━━┻━━━┛" << endl;
            if (slot1 == slot2 && slot2 == slot3) {
              cout << "You won!" << endl;
              return 4;
            } else {
              cout << "You lost." << endl;
              return 0;
            }
        }
}
