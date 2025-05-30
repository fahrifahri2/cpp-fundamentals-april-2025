#include <iostream>
#include <string>
#include <vector>

void printVector(const std::vector<char>& v) {
    for (std::vector<char>::size_type i = 0; i < v.size(); i++) {
        std::cout << v[i];
    }
    std::cout << std::endl;
}

int main() {
    std::string text;
    std::getline(std::cin, text);

    std::vector<char> result;

    if (!text.empty()) {
        result.push_back(text[0]);
    }

    for (std::string::size_type i = 1; i < text.size(); i++) {
        if (result.back() != text[i]) {
            result.push_back(text[i]);
        }
    }

    printVector(result);
    return 0;
}