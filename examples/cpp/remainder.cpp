#include <iostream>

int main() {
    int a, b;
    std::cin >> a;
    std::cin >> b;
    int remainder = a % b;
    std::cout << remainder << std::endl;
}