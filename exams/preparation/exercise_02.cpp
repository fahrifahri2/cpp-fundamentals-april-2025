#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

void printVector(const std::vector<char>& v) {
    for (const char& c : v) {
        std::cout << c;
    }
    std::cout << std::endl;
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::vector<char> result;
    result.reserve(input.size());

    if (!input.empty()) {
        result.push_back(input[0]);
    }

    for (int i = 1; i < input.size(); i++) {
        if (constexpr std::array<char, 5> VOWELS = {'a', 'e', 'i', 'o', 'u'};
            std::find(VOWELS.begin(), VOWELS.end(), input[i]) != VOWELS.end() || input[i] != input[i - 1]) {
            result.push_back(input[i]);
        }
    }

    printVector(result);
    return 0;
}