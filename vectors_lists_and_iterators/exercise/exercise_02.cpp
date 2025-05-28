#include <iostream>
#include <vector>
#include <string>

bool isBalanced(const std::string& brackets) {
    std::vector<char> stack;

    for (const char bracket : brackets) {
        if (bracket == '{') {
            if (!stack.empty() && (stack.back() == '[' || stack.back() == '(')) {
                return false;
            }
            stack.push_back(bracket);

        } else if (bracket == '[') {
            if (!stack.empty() && stack.back() == '(') {
                return false;
            }
            stack.push_back(bracket);

        } else if (bracket == '(') {
            stack.push_back(bracket);

        } else if (bracket == '}') {
            if (stack.empty() || stack.back() != '{') {
                return false;
            }
            stack.pop_back();

        } else if (bracket == ']') {
            if (stack.empty() || stack.back() != '[') {
                return false;
            }
            stack.pop_back();

        } else if (bracket == ')') {
            if (stack.empty() || stack.back() != '(') {
                return false;
            }
            stack.pop_back();
        }
    }

    return stack.empty();
}

int main() {
    std::string brackets;
    std::cin >> brackets;

    std::cout << (isBalanced(brackets) ? "valid" : "invalid") << std::endl;
    return 0;
}