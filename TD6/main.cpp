#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

#include "vector.h"

Vector genVecOur(std::size_t size)
{
    Vector v(size, 42.0F);
    return v;
}

std::vector<float> genVecStd(std::size_t size)
{
    std::vector<float> v(size, 42.0F);
    return v;
}

int main()
{
    std::cout << std::fixed << std::setprecision(9) << std::left;

    Vector vec_our;
    std::vector<float> vec_std;
    float res = 0.0F;

    for (auto size{1ul}; size < 1000000000ul; size *= 100)
    {
        const auto start_our = std::chrono::high_resolution_clock::now();
        vec_our = genVecOur(size);
        const auto end_our = std::chrono::high_resolution_clock::now();
        res += vec_our[vec_our.size()-1];
        const std::chrono::duration<double> diff_our = end_our - start_our;
        std::cout << "Time to get a Vector of " << std::setw(9)
                  << size << " ints :      " << diff_our << '\n';

        const auto start_std = std::chrono::high_resolution_clock::now();
        vec_std = genVecStd(size);
        const auto end_std = std::chrono::high_resolution_clock::now();
        const std::chrono::duration<double> diff_std = end_std - start_std;
        res += vec_std.back();

        std::cout << "Time to get a std::vector of " << std::setw(9)
                  << size << " ints : " << diff_std << '\n';
    }
    std::cout << res;

}
