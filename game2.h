#ifndef GAME2_H
#define GAME2_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

struct Card {
    string rank;
    int value;
};

const vector<Card> deck = {
    {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5},
    {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9},
    {"10", 10}, {"Jack", 10}, {"Queen", 10},
    {"King", 10}, {"Ace", 11}
};

void shuffle_deck(vector<Card>& deck);

void deal_card(vector<Card>& deck, vector<string>& hand, int& score);

void display_hand(vector<string>& hand, int& score);

int game2(std::string playerName);

#endif
