//MAIN//edit function before
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include <algorithm>
#include <thread>
#include <list>
#include <fstream>
#include "game1.h"
#include "game2.h"
#include "game3.h"

using namespace std;
struct Score {
    string name;
    int points;
};

void save_score(vector<Score>& scores, string name, int points) {
    bool found = false;
    for (Score& score : scores) {
        if (score.name == name) {
            score.points = points;
            found = true;
            break;
        }
    }
    if (!found) {
        scores.push_back({name, points});
    }
}


void display_scores(vector<Score>& scores) {
    cout << "SCOREBOARD" << endl;
    cout << "----------" << endl;
    for (Score score : scores) {
        cout << score.name << ": " << score.points << endl;
    }
}

void save_scores_to_file(vector<Score>& scores, string filename) {
    ofstream outfile(filename, ios::app); //append
    for (Score score : scores) {
        outfile << score.name << "," << score.points << endl;
    }
    outfile.close();
}

void load_scores_from_file(vector<Score>& scores, string filename) {
    ifstream infile(filename);
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            size_t pos = line.find(",");
            if (pos != string::npos) {
                string name = line.substr(0, pos);
                int points = stoi(line.substr(pos + 1));
                bool found = false;
                for (Score& score : scores) {
                    if (score.name == name) {
                        score.points = points;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    scores.push_back({name, points});
                }
            }
        }
        infile.close();
    }
}

void print_loading(string game_name) {
    cout << "Loading";
    for (int i = 0; i < 3; i++) {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << endl << "Connecting";
    for (int i = 0; i < 3; i++) {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << endl << "Welcome to " << game_name << endl;
}

void print_box(vector<string> colors, int index) {
    int box_width = 80;
    int arrow_pos = index * (box_width / colors.size()) + (box_width / (2 * colors.size()));
    
    cout << "  +";
    for (int i = 0; i < box_width - 2; i++) {
        cout << "-";
    }
    cout << "+" << endl;
    
    for (int i = 0; i < colors.size(); i++) {
        int item_pos = i * (box_width / colors.size()) + (box_width / (2 * colors.size()));
        cout << "  |";
        for (int j = 0; j < box_width - 2; j++) {
            if (j >= arrow_pos - 5 && j < arrow_pos + 6 && i == index) {
                if (j == arrow_pos - 2) {
                    cout << "^ " << colors[index];
                    j += colors[index].size() + 1;
                } else {
                    cout << " ";
                }
            } else if (j == item_pos && i != index) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << "|" << endl;
    }
    
    cout << "  +";
    for (int i = 0; i < box_width - 2; i++) {
        cout << "-";
    }
    cout << "+" << endl;
}
void display_rules() {
    cout << "CASINO GAME RULES" << endl;
    cout << "-----------------" << endl;
    cout << "1. You start with 10 points." << endl;
    cout << "2. Each spin of the wheel costs 2 points." << endl;
    cout << "3. The wheel can land on 'Minus', 'Plus', or one of the mini-games." << endl;
    cout << "4. If you land on 'Minus', you lose 2 points." << endl;
    cout << "5. If you land on 'Plus', you win 5 points." << endl;
    cout << "6. If you land on a mini-game, you'll have a chance to win more points." << endl;
    cout << "7. You can keep spinning the wheel as long as you have at least 2 points." << endl;
    cout << "8. Your final score will be displayed on the scoreboard." << endl;
    cout << "9. Once you've played a mini-game, you cannot play it again in the same session." << endl;
    cout << endl;
}

bool game1_played = false;
bool game2_played = false;
bool game3_played = false;



int main() {
    vector<Score> scores;
    cout << "CASINO" << endl;
    display_rules();

    string player_name;
    cout << "Enter your name: ";
    getline(cin, player_name);

    int player_points = 10;
    cout << "Welcome, " << player_name << "! You have " << player_points << " points." << endl;
    cout << "You can spin the wheel once. Each spin costs 2 points." << endl;
    
    bool spin_again = true;
    string last_color = "";  
    while (spin_again) {
        cout << "You currently have " << player_points << " points." << endl;
        cout << "Press Enter to spin the wheel...";
        cin.ignore();

        // Deduct 50 points for spinning the wheel
        player_points -= 2;
        cout << endl << "You now have " << player_points << " points." << endl;

        srand(time(NULL));
        
        vector<string> colors = {"Minus", "Plus"};
        if (!game1_played) {
            colors.push_back("Hangman");
        }
        if (!game2_played) {
            colors.push_back("BJ");
        }
        if (!game3_played) {
            colors.push_back("Slot");
        }

        int index = rand() % colors.size();
        string selected_color = colors[index];
        
        print_box(colors, index);
        cout << endl << "You spun: " << selected_color << endl;

        if (selected_color == "Minus") {
            player_points -= 2;
            cout << "Nice try, you lost 2 points! You now have " << player_points << " points." << endl;
        } else if (selected_color == "Plus") {
            player_points += 5;
            cout << "Congrats! You won 5 points! You now have " << player_points << " points." << endl;
        } else if (selected_color == "BJ") {
            print_loading("BJ");
            player_points += game2(player_name);
            colors.erase(remove(colors.begin(), colors.end(), "BJ"), colors.end());
            game2_played = true;
            
        } else if (selected_color == "Slot") {
            print_loading("Slot");
            player_points += game3(player_name);
            colors.erase(remove(colors.begin(), colors.end(), "Slot"), colors.end());
            game3_played = true;
        } else if (selected_color == "Hangman") {
            print_loading("Hangman");
            player_points += game1(player_name);
            colors.erase(remove(colors.begin(), colors.end(), "Hangman"), colors.end());
            game1_played = true;
            // player_points -= game1();
        }

        if (player_points >= 2) {
            cout << "Press Enter to spin the wheel again, or type 'done' to exit." << endl;
            string input;
            getline(cin, input);
            if (input == "done") {
                cout << "Game over! You finished with " << player_points << " points." << endl;
                spin_again = false;
            }
        } else {
            cout << "You do not have enough points to spin again. Game over!" << endl;
            spin_again = false;
        }
    }
    save_score(scores, player_name, player_points);
    save_scores_to_file(scores, "scores.txt");
    load_scores_from_file(scores, "scores.txt");
    display_scores(scores);

    return 0;
}
