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
    std::unordered_map<int, std::string> board({
        { 1, "1" }, { 2, "2" }, { 3, "3" },
        { 4, "4" }, { 5, "5" }, { 6, "6" },
        { 7, "7" }, { 8, "8" }, { 9, "9" }
    });
    const char *renderBoard =
    "-------------------\n"
    "|  x  |  x  |  x  |\n"
    "-------------------\n"
    "|  x  |  x  |  x  |\n"
    "-------------------\n"
    "|  x  |  x  |  x  |\n"
    "-------------------\n";
    std::cout << renderBoard << std::endl;
    enterMove(1);
    return 0;
}