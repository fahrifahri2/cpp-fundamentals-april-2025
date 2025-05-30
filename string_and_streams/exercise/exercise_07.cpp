#include <iostream>
#include <string>

int main() {
    std::string text, findStr, replaceStr;
    std::getline(std::cin, text);
    std::getline(std::cin, findStr);
    std::getline(std::cin, replaceStr);

    std::string::size_type pos = 0;
    pos = text.find(findStr, pos);

    while (pos != std::string::npos) {
        text.replace(pos, findStr.size(), replaceStr);
        pos += replaceStr.size();
        pos = text.find(findStr, pos);
    }

    std::cout << text << std::endl;
    return 0;
}