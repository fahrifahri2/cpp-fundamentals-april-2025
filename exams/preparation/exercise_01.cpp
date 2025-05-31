#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    std::vector<int> nums;
    nums.reserve(n);

    std::string input;
    std::getline(std::cin, input);

    std::istringstream iss(input);
    int sum = 0;
    int num;

    while (iss >> num) {
        nums.push_back(num);
        sum += num;
    }

    int evenSum = 0, oddSum = 0;
    const double avg = static_cast<double>(sum) / n;

    for (std::vector<int>::size_type i = 0; i < nums.size(); i++) {
        if (nums[i] > avg) {
            continue;
        }

        if (i % 2 == 0) {
            evenSum += nums[i];
        } else {
            oddSum += nums[i];
        }
    }

    std::cout << evenSum * oddSum << std::endl;
    return 0;
}