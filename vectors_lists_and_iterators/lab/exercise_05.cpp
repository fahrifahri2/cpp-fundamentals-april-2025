#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

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

    std::string command;
    std::getline(std::cin, command);

    std::istringstream iss;
    std::string action;

    while (command != "end") {
        iss.clear();
        iss.str(command);
        iss >> action;

        if (action == "Add") {
            int number;
            iss >> number;
            numbers.push_back(number);
        } else if (action == "Remove") {
            int number;
            iss >> number;
            numbers.erase(std::remove(numbers.begin(), numbers.end(), number), numbers.end());
        } else if (action == "RemoveAt") {
            std::vector<int>::difference_type index;
            iss >> index;
            numbers.erase(numbers.begin() + index);
        } else if (action == "Insert") {
            std::vector<int>::difference_type index;
            int number;
            iss >> number >> index;
            numbers.insert(numbers.begin() + index, number);
        }

        std::getline(std::cin, command);
    }

    printVector(numbers);
    return 0;
}