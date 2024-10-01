
#include <iostream>

void average(int tab[], int size) {
    int sum = 0;
    for (int i =0 ; i<size; i++){
        sum += tab[i];
    }
    float average = static_cast<float>(sum) / size;
    std::printf("average = %f\n",average);
}

int fibo(int n) {
    if (n < 2) {
        return n;
    }
    else {
        int n1 = 1;
        int n2 = 2;
        for(int i = 2; i <= n; i++) {
            int n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
        }
        return n1;
    }
}


int main() {
    int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = std::size(tab);
    average(tab, size);
    int i = fibo(10);
    std::cout << i << std::endl;
    return 0;
}