#include <iostream>
#include <fstream>
#include <string>

int countNotEquals(std::string line) {
    int count = 0;
    size_t pos = 0;
    while ((pos = line.find("!=", pos)) != std::string::npos) {
        count++;
        pos += 2; // Переміщаємо позицію вказівника за підрядок "!="
    }
    return count;
}

int main() {
    std::ifstream file("myfile.dat");
    if (!file.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }

    std::string line;
    int totalCount = 0;

    while (std::getline(file, line)) {
        int countInLine = countNotEquals(line);
        totalCount += countInLine;
    }

    std::cout << "Number of characters '!=': " << totalCount << std::endl;

    file.close();
    return 0;
}
