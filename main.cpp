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
    ofstream outfile(filename);
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

bool game1_played = false;
bool game2_played = false;
bool game3_played = false;



int main() {
    vector<Score> scores;
    cout << "CASINO" << endl;

    string player_name;
    cout << "Enter your name: ";
    getline(cin, player_name);

    int player_points = 10000;
    cout << "Welcome, " << player_name << "! You have " << player_points << " points." << endl;
    cout << "You can spin the wheel once. Each spin costs 50 points." << endl;
    
    bool spin_again = true;
    string last_color = "";  
    while (spin_again) {
        cout << "You currently have " << player_points << " points." << endl;
        cout << "Press Enter to spin the wheel...";
        cin.ignore();

        // Deduct 50 points for spinning the wheel
        player_points -= 50;
        cout << endl << "You now have " << player_points << " points." << endl;

        srand(time(NULL));
        
        vector<string> colors = {"Minus", "Plus"};
        if (!game1_played) {
            colors.push_back("game1");
        }
        if (!game2_played) {
            colors.push_back("game2");
        }
        if (!game3_played) {
            colors.push_back("game3");
        }

        int index = rand() % colors.size();
        string selected_color = colors[index];
        
        print_box(colors, index);
        cout << endl << "You spun: " << selected_color << endl;

        if (selected_color == "Minus") {
            player_points -= 50;
            cout << "Nice try, you lost 50 points! You now have " << player_points << " points." << endl;
        } else if (selected_color == "Extra Money") {
            player_points += 100;
            cout << "Congrats! You won 100 points! You now have " << player_points << " points." << endl;
        } else if (selected_color == "game2") {
            print_loading("game2");
            colors.erase(remove(colors.begin(), colors.end(), "game2"), colors.end());
            game2_played = true;
            
        } else if (selected_color == "game3") {
            print_loading("game3");
            colors.erase(remove(colors.begin(), colors.end(), "game3"), colors.end());
            game3_played = true;
        } else if (selected_color == "game1") {
            print_loading("game1");
            colors.erase(remove(colors.begin(), colors.end(), "game1"), colors.end());
            game1_played = true;
            // player_points -= game1();
        }

        if (player_points >= 50) {
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
