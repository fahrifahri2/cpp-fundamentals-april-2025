#include <iostream>
#include <vector>
#include <string>
#include <sstream>

void readVector(std::vector<int>& v) {
    std::string input;
    std::getline(std::cin, input);

    std::istringstream iss(input);
    int number;

    while (iss >> number) {
        if (number > 0) {
            v.push_back(number);
        }
    }
}

void printReversedVector (const std::vector<int>& v) {
    for (std::vector<int>::size_type i = v.size() - 1; i > 0; i--) {
        std::cout << v[i] << ' ';
    }
    std::cout << v[0] << std::endl;
}

int main () {
    std::vector<int> numbers;
    readVector(numbers);

    if (numbers.empty()) {
        std::cout << "empty" << std::endl;
    } else {
        printReversedVector(numbers);
    }

    return 0;
}