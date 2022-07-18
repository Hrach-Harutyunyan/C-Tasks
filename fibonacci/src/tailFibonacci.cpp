#include "fibonacci.hpp"

int tailFibonacci (int N, int first, int second) {
    if (N == 1) return first;
    if (N == 2) return second;
    return tailFibonacci(N - 1, second, first + second);
}