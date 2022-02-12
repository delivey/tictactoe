// g++ main.cpp -o tictactoe.exe && ./tictactoe.exe
#include <ctype.h>
#include <iostream>
#include <unordered_map>
#include <stdlib.h>
#include <stdio.h>

int enterMove(int player) {
    int moved; 
    std::string playerS = std::to_string(player);
    std::cout << "Player " + playerS + ", enter move: " << std::endl;
    std::cin >> moved; // Get user input from the keyboard
    return moved;
}

void renderGameOver() {
    std::cout << "Game Over!" << std::endl;
}

int checkForWin(std::unordered_map<int, char> &board) {
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
        if (square.first % 3 && sameInARow == 3) {
            std::cout << "END. Same in a row: " << sameInARow << " last Symbol: " << lastSymbol << std::endl;
            return 1;
        }
    }
    return 0;
}

int makeMove(int move, int playerTurn, std::unordered_map<int, char> &board) {
    std::unordered_map<int, char> players({
        {0, 'X'},
        {1, 'O'}
    });
    char symbol = players.find(playerTurn)->second;
    char symbolOnBoard = board.find(move)->second;
    if (!isalpha(symbolOnBoard)) {
        board.at(move) = symbol;
        return 0;
    } else {
        return 1;
    }
}

int main() {
    bool gameEnded = false;
    bool playerTurn = 0;
    std::unordered_map<int, char> board({
        { 1, '1' }, { 2, '2' }, { 3, '3' },
        { 4, '4' }, { 5, '5' }, { 6, '6' },
        { 7, '7' }, { 8, '8' }, { 9, '9'}
    });

    while (!gameEnded) {
        // system("cls");
        auto one = board.find(1)->second;
        auto two = board.find(2)->second;
        auto three = board.find(3)->second;
        auto four = board.find(4)->second;
        auto five = board.find(5)->second;
        auto six = board.find(6)->second;
        auto seven = board.find(7)->second;
        auto eight = board.find(8)->second;
        auto nine = board.find(9)->second;

        const char *renderBoard =
        "-------------------\n"
        "|  %c  |  %c  |  %c  |\n"
        "-------------------\n"
        "|  %c  |  %c  |  %c  |\n"
        "-------------------\n"
        "|  %c  |  %c  |  %c  |\n"
        "-------------------\n";
        printf(renderBoard, one, two, three, four, five, six, seven, eight, nine);
        int move = enterMove(playerTurn);
        makeMove(move, playerTurn, board);
        int gameOver = checkForWin(board);
        if (gameOver) {
            gameEnded = true;
            renderGameOver();
        }
        playerTurn = !playerTurn;
    };
}