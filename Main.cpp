#include <iostream>
#include <stdio.h>

std::string board[9] = { " ", " ", " ", " ", " ", " ", " ", " ", " " };
int player = 1;
int position = 0;

void start_screen();
bool is_winner();
bool filled_board();
void display_board();
void setpos();
void update_board();
void change_player();
void take_turn();
void game_end();

int main()
{
    start_screen();
    take_turn();
    game_end();
}

void start_screen()
{
    // Displays the "start screen".
    // Displays the board with positions 1-9.
    std::cout << "Press [Enter] to begin.";
    getchar();
    std::cout << " " << std::endl;
    std::cout << "Welcome to:" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "***********" << std::endl;
    std::cout << "Tic-Tac-Toe" << std::endl;
    std::cout << "***********" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Player 1) X" << std::endl;
    std::cout << "Player 2) O" << std::endl;
    std::cout << " " << std::endl;
    std::cout << " ----- ----- ----- " << std::endl;
    std::cout << "|     |     |     |" << std::endl;
    std::cout << "|  1  |  2  |  3  |" << std::endl;
    std::cout << "|     |     |     |" << std::endl;
    std::cout << " ----- ----- ----- " << std::endl;
    std::cout << "|     |     |     |" << std::endl;
    std::cout << "|  4  |  5  |  6  |" << std::endl;
    std::cout << "|     |     |     |" << std::endl;
    std::cout << " ----- ----- ----- " << std::endl;
    std::cout << "|     |     |     |" << std::endl;
    std::cout << "|  7  |  8  |  9  |" << std::endl;
    std::cout << "|     |     |     |" << std::endl;
    std::cout << " ----- ----- ----- " << std::endl;
}

bool is_winner()
{
    /*
    The is_winner function calculates if there is a winner.

    The is_winner function is a boolean function that returns only the values true or false.

    if winner = false the game carries on (runs the "take_turn" function, which is a while loop).
    if winner = true the player is congratulated and the game ends ("game_end" function is triggered).

    Example of win: 
    If board 0, 1 and 2 in the array are equal to each other (exception: " "), there is a winner.
    */

    bool winner = false;
    // checking the rows
    if ((board[0] == board[1]) && (board[1] == board[2]) && board[0] != " ")
    {
        winner = true;
    }
    else if ((board[3] == board[4]) && (board[4] == board[5]) && board[3] != " ")
    {
        winner = true;
    }

    else if ((board[6] == board[7]) && (board[7] == board[8]) && board[6] != " ")
    {
        winner = true;
    }

    // checking the columns

    else if ((board[0] == board[3]) && (board[3] == board[6]) && board[0] != " ")
    {
        winner = true;
    }

    else if ((board[1] == board[4]) && (board[4] == board[7]) && board[1] != " ")
    {
        winner = true;
    }

    else if ((board[2] == board[5]) && (board[5] == board[8]) && board[2] != " ")
    {
        winner = true;
    }

    // checking the diagonals

    else if ((board[0] == board[4]) && (board[4] == board[8]) && board[0] != " ")
    {
        winner = true;
    }

    else if ((board[2] == board[4]) && (board[4] == board[6]) && board[2] != " ")
    {
        winner = true;
    }

    return winner;

}

bool filled_board()
{
    // Determines if the board is full or not.
    // If there are no more " " spaces left on the board, the board is filled.
    // If the board is full the game is a tie. (Returns filled = true).
    // If the board isn't full yet, the game carries on (see take_turn function). 
    // Loops until filled = true.
    bool filled = true;
        for (int i = 0; i < 9; i++)
        {
            if (board[i] == " ") 
            {
                filled = false;
            }
        }
        return filled;
}

void display_board()
{
    // Displays the board.
    // The values of all positions of the array are " " by default, and will appear as empty.
    // As players take their turns the array attains values of either X or O, which are displayed on the board.
    std::cout << " ----- ----- ----- " << std::endl;
    std::cout << "|     |     |     |" << std::endl;
    std::cout << "|  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  |" << std::endl;
    std::cout << "|     |     |     |" << std::endl;
    std::cout << " ----- ----- ----- " << std::endl;
    std::cout << "|     |     |     |" << std::endl;
    std::cout << "|  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  |" << std::endl;
    std::cout << "|     |     |     |" << std::endl;
    std::cout << " ----- ----- ----- " << std::endl;
    std::cout << "|     |     |     |" << std::endl;
    std::cout << "|  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  |" << std::endl;
    std::cout << "|     |     |     |" << std::endl;
    std::cout << " ----- ----- ----- " << std::endl;
}

void setpos() 
{
    // Prompts the user to choose a position on the board.
    std::cout << "Player " << player << " enter : 1-9" << std::endl;
    while (!(std::cin >> position)) {
        std::cout << "Please enter a valid number between 1-9." << std::endl;
        std::cin.clear();
        std::cin.ignore();
        // forces user to enter a valid number between 1-9.
    }
    // If the position cosen is not open (!= " ").
    // Prints this message:
    while (board[position - 1] != " ") {
        std::cout << "That position is already chosen!" << std::endl;
        std::cout << "Try again." << std::endl;
        std::cout << "Player " << player << "s turn." << std::endl;
        std::cout << "Please enter a valid number between 1-9." << std::endl;
    // Prompts user to try again:
        std::cin >> position;
        std::cout << " " << std::endl;
    }
}

void update_board() 
{
    // We use [position - 1].
    // Because board is 0-8 and position is 1-9.
    // If player = 1, board displays X.
    // If not, board displays O.
    if (player == 1) {
        board[position - 1] = "X";
    }
    else {
        board[position - 1] = "O";
    }
}

void change_player() 
{
    // If player = 1, player increses to 2 next turn.
    // If player != 1, player decreces by 1 next turn.
    // Player alternates by 1 and 2.
    if (player == 1) {
        player++;
    }
    else {
        player--;
    }
}

void take_turn() 
{
    //as long as there is no winner AND there has not been a tie:
    while (!is_winner() && !filled_board()) {
        setpos();
        update_board();
        change_player();
        display_board();
    }
}

void game_end() 
{
    //Prints if there is a winner, or if theres a tie.
    //Game ends.
    if (is_winner()) {
        std::cout << "You won! Congratulations!" << std::endl;
    }
    else if (filled_board()) {
        std::cout << "It is a tie!" << std::endl;
    }
}