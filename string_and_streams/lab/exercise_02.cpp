#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::istringstream iss(input);
    std::string word;

    while (iss >> word) {
        for (int i = 0; i < word.size(); i++) {
            std::cout << word;
        }
    }

    std::cout << std::endl;
    return 0;
}