
#include <iostream>

void average(int tab[], int size) {
    int sum = 0;
    for (int i =0 ; i<size; i++){
        sum += tab[i];
    }
    float average = static_cast<float>(sum) / size;
    std::printf("average = %f\n",average);
}

int main() {
    int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = std::size(tab);
    average(tab, size);
    return 0;
}