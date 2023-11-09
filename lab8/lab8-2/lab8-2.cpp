#include <iostream>

void printCharacter(char ch, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << ch;
    }
    std::cout << std::endl;
}

int main() {
    char symbol;
    int count;

    std::cout << "Enter a character: ";
    std::cin >> symbol;

    std::cout << "Enter a non-zero integer: ";
    std::cin >> count;

    if (count != 0) {
        printCharacter(symbol, count);
    }
    else {
        std::cout << "Error: Second argument must be non-zero." << std::endl;
    }

    return 0;
}
