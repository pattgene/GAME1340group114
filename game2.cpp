#include "game2.h"

void shuffle_deck(vector<Card>& deck) {
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);
}

void deal_card(vector<Card>& deck, vector<string>& hand, int& score) {
    Card card = deck.back();
    deck.pop_back();
    // Assigns value of Ace to be 1 or 11
    if (card.rank == "Ace (1)" || card.rank == "Ace (11)") {
        if (score + 11 <= 21) {
            score += 11;
            hand.push_back("Ace (11)");
        } else {
            score += 1;
            hand.push_back("Ace (1)");
        }
    } else {
        hand.push_back(card.rank);
        score += card.value;
    }
}

void display_hand(vector<string>& hand, int& score) {
    cout << "Your hand: ";
    for (int i = 0; i < int(hand.size()); i++) {
        cout << hand[i] << " ";
    }
    cout << endl << "Your score: " << score << endl;
}

int game2(std::string playername) {
    cout << "Welcome, " << playername << ", to Game 2." <<endl;
    cout << "THIS GAME IS BLACK JACK!!!!! " <<endl;
    cout << "You have to win our CASINO BOSS" <<endl;
    cout << "Whoever gets closest to 21 without going over it, wins the game" <<endl;
    cout << "GOOD LUCK!!!" <<endl;
    vector<Card> deck_copy = deck;
    shuffle_deck(deck_copy);
    vector<string> player_hand;
    vector<string> dealer_hand;
    int player_score = 0;
    int dealer_score = 0;

    deal_card(deck_copy, player_hand, player_score);
    deal_card(deck_copy, dealer_hand, dealer_score);
    deal_card(deck_copy, player_hand, player_score);
    deal_card(deck_copy, dealer_hand, dealer_score);

    display_hand(player_hand, player_score);

    while (player_score < 21) {
        char choice;
        // Asks player whether they want to draw another card
        cout << "Hit or stand? (H/S): ";
        cin >> choice;
        if (choice == 'H' || choice == 'h') {
            deal_card(deck_copy, player_hand, player_score);
            display_hand(player_hand, player_score);
        } else {
            break;
        }
    }

    while (dealer_score < 17) {
        deal_card(deck_copy, dealer_hand, dealer_score);
    }
    // Determine the winner
    cout << "Dealer's hand: ";
    for (int i = 0; i < int(dealer_hand.size()); i++) {
        cout << dealer_hand[i] << " ";
    }
    cout << endl << "Dealer's score: " << dealer_score<< endl;
    if (player_score > 21) {
        cout << "Bust! You lose." << endl;
        return 0;
    } else if (dealer_score > 21) {
        cout << "Dealer busts! You win." << endl;
        return 4;
    } else if (player_score > dealer_score) {
        cout << "You win!" << endl;
        return 4;
    } else if (dealer_score > player_score) {
        cout << "You lose." << endl;
        return 0;
    } else {
        cout << "Draw" << endl;
        return 0;
    }
}
