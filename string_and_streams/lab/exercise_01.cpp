#include <iostream>
#include <string>

int main() {
    std::string word;
    std::cin >> word;

    while (word != "end") {
        std::string reversedWord(word.rbegin(), word.rend());
        std::cout << word << " = " << reversedWord << std::endl;
        std::cin >> word;
    }

    return 0;
}