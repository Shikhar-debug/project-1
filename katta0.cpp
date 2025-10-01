#include <iostream>
using namespace std;

// Global variables
char board[3][3];
char currentPlayer = 'X';

// Function to initialize the board
void initializeBoard() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = '1' + (i * 3 + j);  // Fill with 1 to 9
}

// Function to display the board
void printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Function to check for a win
bool checkWin() {
    // Rows and columns
    for (int i = 0; i < 3; ++i)
        if ((board[i][0] == currentPlayer &&
             board[i][1] == currentPlayer &&
             board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer &&
             board[1][i] == currentPlayer &&
             board[2][i] == currentPlayer))
            return true;

    // Diagonals
    if ((board[0][0] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][0] == currentPlayer))
        return true;

    return false;
}

// Function to check for a draw
bool checkDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

// Function to switch player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to make a move
bool makeMove(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (position < 1 || position > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move. Try again.\n";
        return false;
    }

    board[row][col] = currentPlayer;
    return true;
}

// Main game function
int main() {
    initializeBoard();
    int move;
    bool gameOver = false;

    cout << "Welcome to Tic Tac Toe (Player X vs Player O)\n";

    while (!gameOver) {
        printBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (!makeMove(move)) continue;

        if (checkWin()) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
        } else if (checkDraw()) {
            printBoard();
            cout << "It's a draw!\n";
            gameOver = true;
        } else {
            switchPlayer();
        }
    }

    return 0;
}
