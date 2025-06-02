#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int size;
    std::cin >> size;
    std::cin.ignore();

    std::string input;
    std::getline(std::cin, input);

    std::istringstream iss(input);
    std::vector<int> numbers;
    numbers.reserve(size);
    int number;

    while (iss >> number) {
        numbers.push_back(number);
    }

    for (int i = 0; i < size - 1; i++) {
        for (std::vector<int>::size_type j = 0; j < numbers.size() - 1; j++) {
            numbers[j] = numbers[j] + numbers[j + 1];
        }
        numbers.pop_back();
    }

    std::cout << numbers[0] << std::endl ;
    return 0;
}