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
    for (std::vector<int>::size_type i = 0; i < v.size() - 1; i++) {
        std::cout << v[i] << ' ';
    }
    std::cout << v[v.size() - 1] <<  std::endl;
}

int main () {
    std::vector<int> numbers;
    readVector(numbers);

    const std::vector<int>::size_type middleIndex = numbers.size() / 2;

    for (std::vector<int>::size_type i = 0; i < middleIndex; i++) {
        numbers[i] += numbers.back();
        numbers.pop_back();
    }

    printVector(numbers);
    return 0;
}