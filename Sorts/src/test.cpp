#include "sorts.hpp"

int main() {
    const int size = 11;
    double arr[size] {3, 2, 1, 5, 6, 1, 7, 8, 6, 7, 2};
    Sort(arr, size);
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

