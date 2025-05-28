#include <iostream>
#include <vector>

void readVector(const int n, std::vector<int>& v) {
    v.reserve(n);

    for (int i = 0; i < n; i++) {
        int number;
        std::cin >> number;
        v.push_back(number);
    }
}

void printVector(const std::vector<int>& v) {
    const std::vector<int>::size_type lastIndex = v.size() - 1;

    for (std::vector<int>::size_type i = 0; i < lastIndex; i++) {
        std::cout << v[i] << ' ';
    }
    std::cout << v[lastIndex] << std::endl;
}

int main () {
    int pipesCount;
    std::cin >> pipesCount;

    std::vector<int> checkup, installation;
    readVector(pipesCount, checkup);
    readVector(pipesCount, installation);

    std::vector<int> result;
    result.reserve(pipesCount);

    for (int i = 0; i < pipesCount; i++) {
        result.push_back(installation[i] / (installation[i] - checkup[i]));
    }

    printVector(result);
    return 0;
}