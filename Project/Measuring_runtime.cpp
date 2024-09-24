//
// Created by hhaym on 24/09/2024.
//

#include <iostream>
#include <chrono>
auto time() {
    return std::chrono::high_resolution_clock::now();
}

void timeTest(int size) {
    std::printf("\nSize : %d\n",size);
    auto time_point = time();
    int tab[size];
    for(int i=0; i<size;i++) {
        tab[i] = i*2;
    }
    auto duree = time()-time_point;
    std::cout << "Creation duration : "<< duree << "\n";

    auto time_point2 = time();
    int sum = 0;
    for(int i:tab) {
        sum += i;
    }
    auto duree2 = time()-time_point2;
    std::cout << "Sum duration : "<< duree2 << "\n";
    std::printf("Sum = %d\n",sum);
}

int main() {
    timeTest(1000);
    timeTest(10000);
    timeTest(100000);
    return 0;
}
