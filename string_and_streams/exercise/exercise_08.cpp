#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

void printVector(const std::vector<std::string>& v) {
    const std::vector<std::string>::size_type lastIndex = v.size() - 1;

    for (std::vector<char>::size_type i = 0; i < lastIndex; i++) {
        std::cout << v[i] << ' ';
    }
    std::cout << v[lastIndex] << std::endl;
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::istringstream iss(input);
    std::string str;

    int sum = 0;
    std::vector<std::string> words;
    words.reserve((input.size() + 1) / 2);

    while (iss >> str) {
        const auto first = str[0] == '-' ? str.begin() + 1 : str.begin();

        if (std::all_of(first, str.end(), ::isdigit)) {
            sum += std::stoi(str);
        } else {
            words.push_back(str);
        }
    }

    std::cout << sum << std::endl;
    printVector(words);
    return 0;
}