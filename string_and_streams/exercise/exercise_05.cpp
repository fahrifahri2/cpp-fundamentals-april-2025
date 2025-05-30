#include <iostream>
#include <string>

bool isCorrect(const std::string& expression) {
    int openingBracketsCount = 0;

    for (const char ch : expression) {
        if (ch == '(') {
            openingBracketsCount++;
        } else if  (ch == ')') {
            if (openingBracketsCount == 0) {
                return false;
            }

            openingBracketsCount--;
        }
    }

    return openingBracketsCount == 0;
}

int main() {
    std::string mathematicalExpression;
    std::cin >> mathematicalExpression;

    if (isCorrect(mathematicalExpression)) {
        std::cout << "correct" << std::endl;
    } else {
        std::cout << "incorrect" << std::endl;
    }
}