#include "stdFunctions.hpp"

int main() {
    
    Pair <int, int> aa {10, 10};
    Pair <int, int> bb {aa};
    std::cout << "first = " <<  bb.first_data;
    std::cout << "\nsecond = " << bb.second_data << std::endl << std::endl;

    std::vector <int> vec {1, 2, 3, 4};
    std::vector <int> result;
    copy_if(vec.begin(), vec.end(), std::back_inserter(result), [] (int k) { return k % 2; });
    for(auto& elem : result) {
        std::cout << elem << " ";
    }
    std::cout << std::endl << std::endl;

    transform(vec.begin(), vec.end(), vec.begin(), [] (int k) {return k * k; });
    for(auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl << std::endl;
    return 0;
}
