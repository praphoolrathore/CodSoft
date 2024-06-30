#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void printBoard() {
    cout << "\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}

bool isDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

void makeMove(char player) {
    int move;
    cout << "Player " << player << ", enter your move (1-9): ";
    cin >> move;

    while (move < 1 || move > 9 || board[(move - 1) / SIZE][(move - 1) % SIZE] == 'X' || board[(move - 1) / SIZE][(move - 1) % SIZE] == 'O') {
        cout << "Invalid move. Try again: ";
        cin >> move;
    }

    board[(move - 1) / SIZE][(move - 1) % SIZE] = player;
}

int main() {
    char currentPlayer = 'X';
    bool gameWon = false;

    while (!gameWon && !isDraw()) {
        printBoard();
        makeMove(currentPlayer);
        gameWon = checkWin();
        if (!gameWon) currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    printBoard();

    if (gameWon) {
        cout << "Player " << currentPlayer << " wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
