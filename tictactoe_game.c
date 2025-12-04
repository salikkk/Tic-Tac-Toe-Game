#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void displayBoard(char board[3][3]);
void initializeBoard(char board[3][3]);
int checkWin(char board[3][3]);
int checkDraw(char board[3][3]);
void playerMove(char board[3][3], char player);
void clearScreen();

int main() {
    char board[3][3];
    char currentPlayer = 'X';
    int gameStatus = 0; 
    char playAgain;
    
    printf("========================================\n");
    printf("   WELCOME TO TIC TAC TOE GAME!\n");
    printf("========================================\n\n");
    
    do {
        initializeBoard(board);
        currentPlayer = 'X';
        gameStatus = 0;
        

        while (gameStatus == 0) {
            clearScreen();
            displayBoard(board);
            
            printf("\nPlayer %c's turn\n", currentPlayer);
            playerMove(board, currentPlayer);
            

            if (checkWin(board)) {
                clearScreen();
                displayBoard(board);
                printf("\n PLAYER %c WINS! \n", currentPlayer);
                gameStatus = 1;
            }

            else if (checkDraw(board)) {
                clearScreen();
                displayBoard(board);
                printf("\n IT'S A DRAW! \n");
                gameStatus = 2;
            }

            else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
        

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
        playAgain = tolower(playAgain);
        
    } while (playAgain == 'y');
    
    printf("\nThanks for playing! Goodbye!\n");
    return 0;
}


void initializeBoard(char board[3][3]) {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
}


void displayBoard(char board[3][3]) {
    printf("\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n");
    printf("\n");
}


void playerMove(char board[3][3], char player) {
    int position;
    int row, col;
    int validMove = 0;
    
    while (!validMove) {
        printf("Enter position (1-9): ");
        scanf("%d", &position);
        

        if (position < 1 || position > 9) {
            printf("Invalid position! Please enter a number between 1 and 9.\n");
            continue;
        }
        

        row = (position - 1) / 3;
        col = (position - 1) % 3;
        

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Position already taken! Choose another position.\n");
        } else {
            board[row][col] = player;
            validMove = 1;
        }
    }
}


int checkWin(char board[3][3]) {

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    

    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }
    

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    
    return 0;
}

int checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
 
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
