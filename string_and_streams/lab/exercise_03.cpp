#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string first, second;
    std::getline(std::cin, first);
    std::getline(std::cin, second);

    std::string::size_type pos = second.find(first);

    while (pos != std::string::npos) {
        second.erase(pos, first.size());
        pos = second.find(first);
    }

    std::cout << second << std::endl;
    return 0;
}