// g++ main.cpp -o tictactoe.exe && ./tictactoe.exe
#include <ctype.h>
#include <iostream>
#include <unordered_map>
#include <stdlib.h>
#include <stdio.h>

const std::unordered_map<int, char> players({
    {0, 'X'},
    {1, 'O'}
});

std::unordered_map<int, char> board({
    { 1, '1' }, { 2, '2' }, { 3, '3' },
    { 4, '4' }, { 5, '5' }, { 6, '6' },
    { 7, '7' }, { 8, '8' }, { 9, '9'}
});

void clearScreen();
int enterMove(int player);
void renderGameOver(int player);
int checkForWin();
int makeMove(int move, int playerTurn);
char fb(int square); // find board
void renderBoard();

int main() {
    int gameOver = 0;
    bool playerTurn = 0;

    while (!gameOver) {
        renderBoard();
        int move = enterMove(playerTurn);
        makeMove(move, playerTurn);
        gameOver = checkForWin();
        if (gameOver) {
            renderBoard();
            renderGameOver(playerTurn);
        }
        playerTurn = !playerTurn;
    };
}

int enterMove(int player) {
    int moved; 
    std::string playerS = std::to_string(player);
    std::cout << "Player " << playerS << ", enter move: " << std::endl;
    std::cin >> moved; 
    return moved;
}

void renderGameOver(int player) {
    char playerSymbol = players.find(player)->second;
    std::cout << "GAME OVER!" << std::endl; 
    std::cout << "Player " << player << " (" << playerSymbol << ") won!";
}

int checkForWin() {
    char lastSymbol = 'n';
    int sameInARow = 1;
    for (auto& square: board) {
        if (isdigit(square.second)) {
            lastSymbol = 'n'; // temp bypass of empty char
            sameInARow = 1;
        }
        if (square.second == lastSymbol) sameInARow++;
        else sameInARow = 1;
        lastSymbol = square.second;

        bool horizontal = square.first % 3 && sameInARow == 3;
        bool vertical = square.first <= 3 && square.second == board.find(square.first+3)->second && square.second == board.find(square.first+6)->second;

        bool diagonalTwo = board.find(3)->second == board.find(5)->second && board.find(5)->second == board.find(7)->second;
        bool diagonalFour = board.find(1)->second == board.find(5)->second && board.find(5)->second == board.find(9)->second;
        bool diagonal = diagonalTwo || diagonalFour;

        if (horizontal || vertical || diagonal) return 1;
    }
    return 0;
}

int makeMove(int move, int playerTurn) {
    char symbol = players.find(playerTurn)->second;
    char symbolOnBoard = board.find(move)->second;
    if (!isalpha(symbolOnBoard)) {
        board.at(move) = symbol;
        return 0;
    } else {
        return 1;
    }
}

char fb(int square) {
    return board.find(square)->second;
}

void clearScreen(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void renderBoard() {
	clearScreen();
    const char *renderBoard =
    "-------------------\n"
    "|  %c  |  %c  |  %c  |\n"
    "-------------------\n"
    "|  %c  |  %c  |  %c  |\n"
    "-------------------\n"
    "|  %c  |  %c  |  %c  |\n"
    "-------------------\n";
    printf(renderBoard, fb(1), fb(2), fb(3), fb(4), fb(5), fb(6), fb(7), fb(8), fb(9));
}