#include "10filesSearch.hpp"

int main() {

    std::vector <std::string> paths {
        "txt/1.txt",
        "txt/2.txt",
        "txt/3.txt",
        "txt/4.txt",
        "txt/5.txt",
        "txt/6.txt",
        "txt/7.txt",
        "txt/8.txt",
        "txt/9.txt",
        "txt/10.txt"
    };
    std::string name = "sophia";
    std::cout << searchInFiles(paths, name);

    return 0;
}


