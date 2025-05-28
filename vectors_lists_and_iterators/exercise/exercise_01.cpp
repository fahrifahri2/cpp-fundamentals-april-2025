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
        v.push_back(number);
    }
}

void printVector(const std::vector<int>& v) {
    const std::vector<int>::size_type lastIndex = v.size() - 1;

    for (std::vector<int>::size_type i = 0; i < lastIndex; i++) {
        std::cout << v[i] << ' ';
    }
    std::cout << v[lastIndex] << std::endl;
}

void printReversedVector(const std::vector<char>& v) {
    const std::vector<int>::size_type lastIndex = v.size() - 1;

    for (std::vector<int>::size_type i = lastIndex; i > 0; i--) {
        std::cout << v[i];
    }
    std::cout << v[0] << std::endl;
}

int main() {
    std::vector<int> first, second;
    readVector(first);
    readVector(second);

    std::vector<char> operations;
    std::vector<int> result;

    if (first.back() < second.back()) {
        std::vector<int>::size_type j = 0;

        for (const int number : second) {
            while (first[j] > number) {
                result.push_back(first[j++]);
                operations.push_back('A');
            }

            result.push_back(number);
            operations.push_back('B');
        }

        for (std::vector<int>::size_type i = j; i < first.size(); i++) {
            result.push_back(first[i]);
            operations.push_back('A');
        }
    } else {
        std::vector<int>::size_type j = 0;

        for (const int number : first) {
            while (second[j] > number) {
                result.push_back(second[j++]);
                operations.push_back('B');
            }

            result.push_back(number);
            operations.push_back('A');
        }

        for (std::vector<int>::size_type i = j; i < second.size(); i++) {
            result.push_back(second[i]);
            operations.push_back('B');
        }
    }

    printReversedVector(operations);
    printVector(result);
    return 0;
}