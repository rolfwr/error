#include <iostream>
#include <ios>

int main() {
    int a, b;
    std::cin.exceptions(std::ios::failbit | std::ios::badbit);
    std::cout.exceptions(std::ios::failbit | std::ios::badbit);
    std::cin >> a;
    std::cin >> b;
    int result = a % b;
    std::cout << result << std::endl;
}