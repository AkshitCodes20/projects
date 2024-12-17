#include <stdio.h>
#include <stdbool.h>

char board[3][3];
char currentPlayer;

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

bool isWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;
    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void changePlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void makeMove() {
    int row, col;
    printf("Player %c, enter your move (row and column): ", currentPlayer);
    scanf("%d %d", &row, &col);
    if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
        board[row - 1][col - 1] = currentPlayer;
    } else {
        printf("Invalid move. Try again.\n");
        makeMove();
    }
}

int main() {
    currentPlayer = 'X';
    initializeBoard();
    while (true) {
        printBoard();
        makeMove();
        if (isWin()) {
            printBoard();
            printf("Player %c wins!\n", currentPlayer);
            break;
        }
        if (isDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
        changePlayer();
    }
    return 0;
}
