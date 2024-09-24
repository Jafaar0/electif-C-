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
    int size = 1000;
    int tab[size];
    for(int i=0; i<size;i++) {
        tab[i] = i*2;
    }
    std::cout << "Creation duration : "<<time()-time_point << "\n";

    auto time_point2 = time();
    int sum = 0;
    for(int i:tab) {
        sum += i;
    }
    std::printf("Sum = %d\n",sum);
    std::cout << "Sum duration : "<<time()-time_point2 << "\n";

    return 0;
}
