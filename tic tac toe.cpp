#include <iostream>
#include <vector>

// Function to print the Tic-Tac-Toe board
void printBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "---------" << std::endl;
    }
}

// Function to check if there's a win
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the board is full (draw)
bool isBoardFull(const std::vector<std::vector<char>>& board) {
    for (const std::vector<char>& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false; // If there's an empty cell, the board isn't full
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameWon = false;

    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;
    
    while (!gameWon && !isBoardFull(board)) {
        std::cout << "Current board:" << std::endl;
        printBoard(board);
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column, 1-3): ";
        std::cin >> row >> col;

        // Check if the input is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            std::cout << "Invalid move. Try again." << std::endl;
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;
        gameWon = checkWin(board, currentPlayer);
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    std::cout << "Final board:" << std::endl;
    printBoard(board);

    if (gameWon) {
        std::cout << "Player " << currentPlayer << " wins! Congratulations!" << std::endl;
    } else {
        std::cout << "It's a draw! Good game!" << std::endl;
    }

    return 0;
}
