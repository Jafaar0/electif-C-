//
// Created by hhaym on 24/09/2024.
//

#include <iostream>
#include <chrono>
auto time() {
    return std::chrono::high_resolution_clock::now();
}

int main() {
    auto time_point = time();
    int tab[1000];
    for(int i=0; i<1000;i++) {
        tab[i] = i*2;
    }
    std::cout << time()-time_point;
    return 0;
}
