//main.cpp first version
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "game1.h"

using namespace std;

vector<string> games = {"game1", "game2", "game3"};

string wheel()
{
    srand(time(NULL));
    int index = rand() % games.size();
    string result = games[index];
    games.erase(games.begin() + index);
    return result;
}

int main()
{
    string play;
    int checkgame1;
    play = wheel();
    cout << play <<endl; // Prints a random game from the vector
    if (play == "game1")
    {
        checkgame1 = game1();
    }
    //check wo or lose game1
    if (checkgame1 == 1){
        cout << "player won game1" << endl;
    }

}




