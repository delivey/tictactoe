#include <iostream>
// g++ main.cpp -o tictactoe.exe && ./tictactoe.exe

int main() {
    const char *renderBoard =
    "-------------------\n"
    "|  x  |  x  |  x  |\n"
    "-------------------\n"
    "|  x  |  x  |  x  |\n"
    "-------------------\n"
    "|  x  |  x  |  x  |\n"
    "-------------------\n";
    std::cout << renderBoard << std::endl;
    return 0;
}