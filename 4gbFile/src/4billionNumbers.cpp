#include "4billionNumbers.hpp"

void fill_random_in_file(const std::string& filePath, std::size_t NumbersCount, std::size_t MaxRange) {
    if (MaxRange > 200 || MaxRange < 0) {
        std::cout << "Invalid Range: [0, 200] is true range:" << std::endl;
        return;
    }
    std::srand(time(NULL));
    std::ofstream fout(filePath, std::ios::out | std::ios::binary);
    try {
        if(!fout.is_open()) throw std::exception();
        
        u_char num;
        for (int i = 0; i < NumbersCount; i++) {
            num = (1 + std::rand() % MaxRange) + 32 ;
            fout << num;
            // std::cout << static_cast<int> (num - 32) << " ";

        }
        // std::cout << std::endl << std::endl;
        fout.close();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

void read_from_file(const std::string& filePath) {
    std::ifstream fin(filePath, std::ios::in | std::ios::binary );
    try {
        if(!fin.is_open()) throw std::exception();
        while(fin.peek() && !fin.eof()) {
            u_char a = 0;
            fin >> a;
            a -= 32;
            // std::cout << static_cast<int> (a) << " ";
        }
        fin.close();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}