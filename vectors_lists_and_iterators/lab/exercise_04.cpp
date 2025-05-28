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

std::vector<int> mergeVectors(const std::vector<int>& firstV,
                              const std::vector<int>& secondV) {
    std::vector<int> result;

    for (std::vector<int>::size_type i = 0; i < secondV.size(); i++) {
        result.push_back(firstV[i]);
        result.push_back(secondV[i]);
    }

    return result;
}

std::vector<int> mergeVectors(const std::vector<int>& biggestV,
                              const std::vector<int>& smallestV,
                              const bool isBiggestFirst) {
    std::vector<int> result;

    if (isBiggestFirst) {
        for (std::vector<int>::size_type i = 0; i < smallestV.size(); i++) {
            result.push_back(biggestV[i]);
            result.push_back(smallestV[i]);
        }
    } else {
        for (std::vector<int>::size_type i = 0; i < smallestV.size(); i++) {
            result.push_back(smallestV[i]);
            result.push_back(biggestV[i]);
        }
    }

    for (std::vector<int>::size_type i = smallestV.size(); i < biggestV.size(); i++) {
        result.push_back(biggestV[i]);
    }

    return result;
}

void printVector(const std::vector<int>& v) {
    for (std::vector<int>::size_type i = 0; i < v.size() - 1; i++) {
        std::cout << v[i] << ' ';
    }
    std::cout << v[v.size() - 1] <<  std::endl;
}

int main () {
    std::vector<int> first, second, result;
    readVector(first);
    readVector(second);

    if (first.size() > second.size()) {
        result = mergeVectors(first, second, true);
    } else if (first.size() < second.size()) {
        result = mergeVectors(second, first, false);
    } else {
        result = mergeVectors(first, second);
    }

    printVector(result);
    return 0;
}