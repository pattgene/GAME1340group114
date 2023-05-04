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

void display_hand(const string& label, const vector<string>& hand, int score) {
    cout << label << ": ";
    for (const string& card : hand) {
        cout << card << " ";
    }
    cout << endl << "Your score: " << score << endl;
}

// Returns True or False based on whether the hand can be split or not
bool can_split(vector<string>& hand) {
    return hand.size() == 2 && hand[0] == hand[1];
}

int game2(std::string playername) {
    cout << "      ___________ \n";
    cout << "     |  _______  |\n";
    cout << "     | |A      | |\n";
    cout << "     | |       | |\n";
    cout << "     | | Black | |\n";
    cout << "     | |       | |\n";
    cout << "     | |_______| |\n";
    cout << "     |  _______  |\n";
    cout << "     | |10     | |\n";
    cout << "     | |       | |\n";
    cout << "     | | Jack  | |\n";
    cout << "     | |       | |\n";
    cout << "     | |_______| |\n";
    cout << "     |           |\n";
    cout << "     |  DEALER   |\n";
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
    
    bool has_split = false;
    vector<string> player_hand2;
    int player_score2 = 0;

    display_hand("", player_hand, player_score);
    
    // Asks player if they would like to split their hand
    if (can_split(player_hand)) {
        char split_choice;
        cout << "You have a pair. Would you like to split? (Y/N): ";
        cin >> split_choice;
        cin.ignore();
        while (!(split_choice == 'Y' || split_choice == 'y' || split_choice == 'N' || split_choice == 'n')) {
            cout << "Invalid input, please try again.";
            cout << "Split? (Y/N): ";
            cin >> split_choice;
        }
        // Splitting program
        if (split_choice == 'Y' || split_choice == 'y') {
            has_split = true;
            player_hand2.push_back(player_hand[1]);
            player_hand.pop_back();
            player_score2 = player_score / 2;
            player_score = player_score2;
            deal_card(deck_copy, player_hand, player_score);
            deal_card(deck_copy, player_hand2, player_score2);
            display_hand("Your hand: ", player_hand, player_score);
            display_hand("Your split hand: ", player_hand2, player_score2);
        }
  

        // Play each hand, including the split hand if applicable.
        vector<vector<string>> hands = {player_hand};
        vector<int> scores = {player_score};
        if (has_split) {
            hands.push_back(player_hand2);
            scores.push_back(player_score2);
        }

        for (int hand_idx = 0; hand_idx < int(hands.size()); ++hand_idx) {
            string hand_label = has_split ? (hand_idx == 0 ? "Your hand" : "Your split hand") : "Your hand";
            while (scores[hand_idx] < 21) {
                char choice;
                cout << hand_label << "Hit or stand? (H/S): ";
                cin >> choice;
                cin.ignore();
                while (!(choice == 'H' || choice == 'h' || choice == 'S' || choice == 's')) {
                    cout << "Invalid input, please try again.";
                    cout << hand_label << "Hit or stand? (H/S): ";
                    cin >> choice;
                }
                if (choice == 'H' || choice == 'h') {
                    deal_card(deck_copy, hands[hand_idx], scores[hand_idx]);
                    display_hand(hand_label, hands[hand_idx], scores[hand_idx]);
                } else {
                    break;
                }
            }
        }
        // Calculating winner for either split hand or normal deck
        int points = 0;
        for (int hand_idx = 0; hand_idx < int(hands.size()); ++hand_idx) {
            string hand_label = has_split ? (hand_idx == 0 ? "Your hand" : "Your split hand") : "Your hand";
            if (scores[hand_idx] > 21) {
                cout << hand_label << " - Bust! You lose." << endl;
            } else if (dealer_score > 21) {
                cout << hand_label << " - Dealer busts! You win." << endl;
                points += 4;
            } else if (scores[hand_idx] > dealer_score) {
                cout << hand_label << " - You win!" << endl;
                points += 4;
            } else if (dealer_score > scores[hand_idx]) {
                cout << hand_label << " - You lose." << endl;
            } else {
                cout << hand_label << " - Draw" << endl;
            }
        }
        return points;

    }

    while (player_score < 21) {
        char choice;
        // Asks player whether they want to draw another card
        cout << "Hit or stand? (H/S): ";
        cin >> choice;
        cin.ignore();
        // Prevents any unwanted input that might cause errors
        while (!(choice == 'H' || choice == 'h' || choice == 'S' || choice == 's')) {
            cout << "Invalid input, please try again.";
            cout << "Hit or stand? (H/S): ";
            cin >> choice;
        }
        if (choice == 'H' || choice == 'h') {
            deal_card(deck_copy, player_hand, player_score);
            display_hand("", player_hand, player_score);
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
