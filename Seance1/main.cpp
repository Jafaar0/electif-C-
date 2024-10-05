#include <iostream>

void printGreetings(int bound) {

    for (int i=1; i<=bound; i+=1) {
        if(i%2==0) {
            std::cout << i << std::endl;
        }
    }
    std::cout << "Hello, World!" << std::endl;

    for (int i=bound; i>=0; i-=1) {
        if(i%2==1) {
            std::cout << i << std::endl;
        }
    }
}

int main() {
    printGreetings(-10);
    return 0;
}
