#include "4billionNumbers.hpp"

int main() {

    int countNumbers = 10;
    int maxRange = 200;

    fill_random_in_file("txt/numbers.txt", countNumbers, maxRange);
    read_from_file("txt/numbers.txt");

    return 0;
}