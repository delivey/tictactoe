// g++ main.cpp -o tictactoe.exe && ./tictactoe.exe
#include <iostream>
#include <unordered_map>

int enterMove(int player) {
    int moved; 
    std::string playerS = std::to_string(player);
    std::cout << "Player " + playerS + ", enter move: " << std::endl;
    std::cin >> moved; // Get user input from the keyboard
    return moved;
}

int main() {
    std::unordered_map<int, char> board({
        { 1, '1' }, { 2, '2' }, { 3, '3' },
        { 4, '4' }, { 5, '5' }, { 6, '6' },
        { 7, '7' }, { 8, '8' }, { 9, '9'}
    });

    auto one = board.find(1);
    auto two = board.find(2);
    auto three = board.find(3);
    auto four = board.find(4);
    auto five = board.find(5);
    auto six = board.find(6);
    auto seven = board.find(7);
    auto eight = board.find(8);
    auto nine = board.find(9);

    const char *renderBoard =
    "-------------------\n"
    "|  %c  |  %c  |  %c  |\n"
    "-------------------\n"
    "|  %c  |  %c  |  %c  |\n"
    "-------------------\n"
    "|  %c  |  %c  |  %c  |\n"
    "-------------------\n";
    printf(renderBoard, one->second, two->second, three->second, four->second, five->second, six->second, seven->second, eight->second, nine->second);
    int move = enterMove(1);
}