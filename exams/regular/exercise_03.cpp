#include <iostream>
#include <vector>
#include <string>
#include <sstream>

void readWages(std::vector<std::string> &wages) {
    std::string input;
    std::getline(std::cin, input);

    while (input != "end") {
        wages.push_back(input == "empty" ? " " : input);
        std::getline(std::cin, input);
    }
}

void printWages(const std::vector<std::string> &wages) {
    std::cout << '|';

    for (const std::string& wage : wages) {
        std::cout << wage << '|';
    }

    std::cout << std::endl;
}

void moveWage(std::vector<std::string> &wages, int oldPos,int newPos) {
    oldPos--;
    newPos--;
    const std::string oldValue = wages[oldPos];

    if (oldPos > newPos) {
        for (std::vector<std::string>::size_type i = oldPos; i > newPos; i--) {
            wages[i] = wages[i - 1];
        }
    } else {
        for (std::vector<std::string>::size_type i = oldPos; i < newPos; i++) {
            wages[i] = wages[i + 1];
        }
    }

    wages[newPos] = oldValue;
}

int main() {
    std::vector<std::string> wagons;
    readWages(wagons);

    std::string command;
    std::getline(std::cin, command);

    std::istringstream iss;
    std::vector<std::string>::difference_type wagonPos;

    while (command != "E") {
        iss.clear();
        iss.str(command);

        char action;
        iss >> action;

        if (action == 'P') {
            printWages(wagons);
        } else if (action == 'M') {
            int oldWagonPos, newWagonPos;
            iss >> oldWagonPos >> newWagonPos;
            moveWage(wagons, oldWagonPos, newWagonPos);
            printWages(wagons);
        } else if (action == 'L') {
            iss >> wagonPos;
            wagons.erase(wagons.begin() + (wagonPos - 1));
            printWages(wagons);
        }

        std::getline(std::cin, command);
    }

    return 0;
}