// g++ main.cpp -o tictactoe.exe && ./tictactoe.exe
#include <iostream>
#include <unordered_map>
#include <stdlib.h>

int enterMove(int player) {
    int moved; 
    std::string playerS = std::to_string(player);
    std::cout << "Player " + playerS + ", enter move: " << std::endl;
    std::cin >> moved; // Get user input from the keyboard
    return moved;
}

int makeMove(int move, int playerTurn, std::unordered_map<int, char> &board) {
    std::unordered_map<int, char> players({
        {0, 'X'},
        {1, 'O'}
    });
    char symbol = players.find(playerTurn)->second;
    std::cout << symbol << std::endl;
    board.at(move) = symbol;
    return 0;
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
        system("cls");
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
        playerTurn = !playerTurn;
    };
}