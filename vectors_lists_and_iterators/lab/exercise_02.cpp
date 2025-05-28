#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void readVector(const int n, std::vector<std::string>& v) {
    v.reserve(n);
    std::string str;

    for (int i = 0; i < n; i++) {
        std::cin >> str;
        v.push_back(str);
    }
}

void printVector (const std::vector<std::string>& v) {
    for (std::vector<int>::size_type i = 0; i < v.size(); i++) {
        std::cout << i + 1 << '.' << v[i] << std::endl;
    }
}

int main () {
    int productsCount;
    std::cin >> productsCount;

    std::vector<std::string> products;
    readVector(productsCount, products);

    std::sort(products.begin(), products.end());
    printVector(products);

    return 0;
}