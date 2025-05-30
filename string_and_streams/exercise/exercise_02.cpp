#include <iostream>
#include <string>

int main() {
    std::string text;
    std::getline(std::cin, text);

    for (char& ch : text) {
        ch += 3;
    }
    
    std::cout << text << std::endl;
    return 0;
}