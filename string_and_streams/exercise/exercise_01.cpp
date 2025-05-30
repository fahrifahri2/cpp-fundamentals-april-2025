#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

bool isValid(const std::string& username) {
    if (username.size() < 3 || username.size() > 16) {
        return false;
    }

    return std::all_of(username.begin(), username.end(), [](const char ch) {
        return isalnum(ch) || ch == '-' || ch == '_';
    });
}

std::vector<std::string> split(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> result;
    std::string::size_type start = 0, end = str.find(delimiter);

    while (end != std::string::npos) {
        result.push_back(str.substr(start, end - start));
        start = end + delimiter.size();
        end = str.find(delimiter, start);
    }

    result.push_back(str.substr(start, str.size() - start));
    return result;
}

int main() {
    const std::string DELIMITER = ", ";

    std::string input;
    std::getline(std::cin, input);

    const std::vector<std::string> usernames = split(input, DELIMITER);

    for (const std::string& username : usernames) {
        if (isValid(username)) {
            std::cout << username << std::endl;
        }
    }

    return 0;
}