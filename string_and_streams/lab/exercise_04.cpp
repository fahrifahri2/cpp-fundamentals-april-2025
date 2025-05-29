#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string str;
    std::cin >> str;

    std::string digits, letters, another;

    for (const char ch : str) {
        if (std::isdigit(ch)) {
            digits += ch;
        } else if (std::isalpha(ch)) {
            letters += ch;
        } else {
            another += ch;
        }
    }

    std::cout << digits << std::endl;
    std::cout << letters << std::endl;
    std::cout << another << std::endl;

    return 0;
}