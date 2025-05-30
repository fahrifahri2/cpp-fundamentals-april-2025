#include <iostream>
#include <string>
#include <vector>
#include <cctype>

void printVector(const std::vector<char>& v) {
    for (std::vector<char>::size_type i = 0; i < v.size(); i++) {
        std::cout << v[i];
    }
    std::cout << std::endl;
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::vector<char> result(input.begin(), input.end());
    bool isUppercase = true;

    for (char& ch : result) {
        if (std::isalpha(ch)) {
            if (isUppercase) {
                ch = std::toupper(ch);
                isUppercase = false;
            }
        } else {
            isUppercase = true;
        }
    }

    printVector(result);
    return 0;
}