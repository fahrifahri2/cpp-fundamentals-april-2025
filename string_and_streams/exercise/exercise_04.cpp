#include <iostream>
#include <string>

int sumEqualSizeStrs(const std::string& firstStr, const std::string& secondStr) {
    int result = 0;

    for (std::string::size_type i = 0; i < firstStr.size(); i++) {
        result += static_cast<int>(firstStr[i]) * static_cast<int>(secondStr[i]);
    }

    return  result;
}


int sumDifferentSizeStrs(const std::string& firstStr, const std::string& secondStr) {
    int result = 0, index = 0;

    if (firstStr.size() > secondStr.size()) {
        while (index < secondStr.size()) {
            result += static_cast<int>(firstStr[index]) * static_cast<int>(secondStr[index]);
            index++;
        }

        for (std::string::size_type i = index; i < firstStr.size(); i++) {
            result += static_cast<float>(firstStr[i]);
        }
    } else {
        while (index < firstStr.size()) {
            result += static_cast<int>(firstStr[index]) * static_cast<int>(secondStr[index]);
            index++;
        }

        for (std::string::size_type i = index; i < secondStr.size(); i++) {
            result += static_cast<float>(secondStr[i]);
        }
    }

    return result;
}


int main() {
    std::string first, second;
    std::cin >> first >> second;

    int sum;

    if (first.size() == second.size()) {
        sum = sumDifferentSizeStrs(first, second);
    } else {
        sum = sumDifferentSizeStrs(first, second);
    }

    std::cout << sum << std::endl;
    return 0;
}