#include <iostream>

int main() {
    for (int i=2; i<=10; i+=2) {
        std::cout << i << std::endl;
    }
    std::cout << "Hello, World!" << std::endl;

    for (int i=9; i>=0; i-=2) {
        std::cout << i << std::endl;
    }
    return 0;
}
