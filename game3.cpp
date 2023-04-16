#include <iostream>
using namespace std;

void display_board(char board[3][3])
{
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i+1 << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool check_win(char board[3][3], char player)
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
        {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }
    // No win condition met
    return false;
}

void game3()
{
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player = 'X';
    bool win = false;
    int row, col;

    cout << "Welcome to Tic Tac Toe!" << endl;
    while (!win)
    {
        display_board(board);
        cout << "Player " << player << ", enter row (1-3): ";
        cin >> row;
        cout << "Player " << player << ", enter column (1-3): ";
        cin >> col;

        // Check if cell is already taken
        if (board[row-1][col-1] != ' ')
        {
            cout << "That cell is already taken. Please try again." << endl;
            continue;
        }

        // Update board
        board[row-1][col-1] = player;

        // Check for win
        if (check_win(board, player))
        {
            win = true;
            cout << "Player " << player << " wins!" << endl;
        }
        // Check for tie
        else if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' &&
                 board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' ' &&
                 board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ')
        {
            win = true;
            cout << "It's a tie!" << endl;
        }

        // Switch player
        if (player == 'X')
        {
            player = 'O';
        }
        else
        {
            player = 'X';
        }
    }

    display_board(board);
}

