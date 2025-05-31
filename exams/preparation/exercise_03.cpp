#include <iostream>
#include <string>
#include <vector>

void printVector(const std::vector<int>& v) {
    for (const int& c : v) {
        std::cout << c << std::endl;
    }
}

int main() {
    std::vector<int> nums;
    nums.reserve(50);

    std::string command;
    std::cin >> command;

    while (command != "end") {
        if (command == "sum") {
            const std::vector<int>::size_type penultIdx = nums.size() - 2;
            nums[penultIdx] = nums[penultIdx] + nums[penultIdx + 1];
            nums.pop_back();
        } else if (command == "subtract") {
            const std::vector<int>::size_type penultIdx = nums.size() - 2;
            nums[penultIdx] = nums[penultIdx + 1] - nums[penultIdx];
            nums.pop_back();
        } else if (command == "concat") {
            const std::vector<int>::size_type penultIdx = nums.size() - 2;
            const std::string concatenated = std::to_string(nums[penultIdx]) + std::to_string(nums[penultIdx + 1]);
            nums[penultIdx] = std::stoi(concatenated);
            nums.pop_back();
        } else if (command == "discard") {
            nums.pop_back();
        } else {
            nums.push_back(std::stoi(command));
        }

        std::cin >> command;
    }

    printVector(nums);
    return 0;
}