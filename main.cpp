#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;
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

int main() {
    cout << "CASINO" << endl;
    string player_name;
    cout << "Enter your name: ";
    getline(cin, player_name);
    int player_points = 100;
    cout << "Welcome, " << player_name << "! You have " << player_points << " points." << endl;
    cout << "Press Enter to spin the wheel...";
    cin.ignore();
    srand(time(NULL));
    vector<string> colors = {"game1", "game2", "game3", "Sweet spin", "Jackpot", "Zonk"};
    int index = rand() % colors.size();
    string selected_color = colors[index];
    int box_width = 40;
    int arrow_pos = index * (box_width / colors.size()) + (box_width / (2 * colors.size()));
    
    cout << "+";
    for (int i = 0; i < box_width - 2; i++) {
        cout << "-";
    }
    cout << "+" << endl;
    
    for (int i = 0; i < colors.size(); i++) {
        int item_pos = i * (box_width / colors.size()) + (box_width / (2 * colors.size()));
        cout << "|";
        for (int j = 0; j < box_width - 2; j++) {
            if (j >= arrow_pos - 5 && j < arrow_pos + 6 && i == index) {
                if (j == arrow_pos - 2) {
                    cout << "^ " << selected_color;
                    j += selected_color.size() + 1;
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
    
    cout << "+";
    for (int i = 0; i < box_width - 2; i++) {
        cout << "-";
    }
    cout << "+" << endl;

   
    
    cout << "You spun: " << selected_color << endl;
if (selected_color == "Jackpot") {
    string chsgme;
    cout << "Choose between game1, game2 or game 3: ";
    getline(cin,chsgme);
    cout << "You choose: " << chsgme << endl;
    if (chsgme == "game1"){
        selected_color = "game1";
    }
    else if (chsgme == "game2"){
        selected_color = "game2";
    } 
    else if (chsgme == "game3"){
        selected_color = "game3";
    }
}
        //if game 1 go game 1 game 2 go game 2 game 3 or game3
if (selected_color == "Zonk") {
    player_points -= 50;
    cout << "Nice try, you lost 50 points! You now have " << player_points << " points." << endl;
} else if (selected_color == "+ 50 point") {
    player_points += 50;
    cout << "Congrats! You won 50 points! You now have " << player_points << " points." << endl;
} else if (selected_color == "game2"){
    print_loading("game2");
} else if (selected_color == "game3"){
    print_loading("game3");
} else if (selected_color == "game1"){
    print_loading("game1");
}

    return 0;
}
//instruction ga boleh dpuble pt + game 1



