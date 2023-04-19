#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game3(string playername) {
    cout << "Welcome, " << playername << ", to Game 3." <<endl;
    cout << "Welcome to the Fruit Slot Machine!" << endl;
    cout << "If you get 3 of the same fruit, you will win 4 points back" << endl;
    cout << "Otherwise, you will lose everything" << endl;
    cout << "Press ENTER to spin the reels! ";
    srand(time(0));
    string* emojis = new string[10];
    emojis[0] = "🍎";
    emojis[1] = "🍊";
    emojis[2] = "🍇";
    emojis[3] = "🍒";
    emojis[4] = "🍓";
    emojis[5] = "🍋";
    emojis[6] = "🍉";
    emojis[7] = "🍌";
    emojis[8] = "🍑";
    emojis[9] = "🍐";
    string slot1 = emojis[rand() % 10];
    string slot2 = emojis[rand() % 10];
    string slot3 = emojis[rand() % 10];
    if (cin.get() == '\n') {
        for(int i = 0; i < 10; i++) {
            cout << "\033[2J\033[1;1H";
            cout << "Spinning the reels!";
            for(int j = 0; j <= i; j++) {
                cout << ".";
            }
            cout << endl;
            cout << "┏━━━┳━━━┳━━━┓" << endl;
            cout << "┃ " << emojis[rand() % 10] << "┃ " << emojis[rand() % 10] << "┃ " << emojis[rand() % 10] << "┃" << endl;
            cout << "┗━━━┻━━━┻━━━┛" << endl;
            cout << "Press ENTER to keep spinning the reels!";
            cin.get();
        }
        cout << "\033[2J\033[1;1H";
        cout << "┏━━━┳━━━┳━━━┓" << endl;
        cout << "┃ " << slot1 << "┃ " << slot2 << "┃ " << slot3 << "┃" << endl;
        cout << "┗━━━┻━━━┻━━━┛" << endl;
        if (slot1 == slot2 && slot2 == slot3) {
            cout << "Congratulations, you won 4 points!" << endl;
            cout << "Thanks for playing the Fruit Slot Machine!" << endl;
            delete[] emojis;
            return 4;
        } else {
            cout << "Sorry, you lost everything." << endl;
            cout << "Thanks for playing the Fruit Slot Machine!" << endl;
            delete[] emojis;
            return 0;
        }
    }
    delete[] emojis;
    return 0;
}
