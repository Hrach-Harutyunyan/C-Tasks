#include "10filesSearch.hpp"

std::string searchInFiles (const std::vector<std::string>& filesPath, const std::string& name) {
    if (!filesPath.size()) {
        return "Invalid array";
    }

    std::string name_copy = name;
    std::transform(name_copy.begin(), name_copy.end(), name_copy.begin(), [] (unsigned char ch) { return std::tolower(ch); });

    for(int i = 0; i < filesPath.size(); ++i) {
        std::ifstream fin (filesPath[i], std::ios_base::in);
        try {
            if(!fin.is_open()) {
                throw std::exception();
            }
            while (!fin.eof()) {
                std::string temp = "";
                fin >> temp;
                std::transform(temp.begin(), temp.end(), temp.begin(), [] (unsigned char ch) { return std::tolower(ch); });
                if(name_copy == temp) {
                    fin.close();
                    return filesPath[i];
                }
            }
            fin.close();
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << filesPath[i] << " is not opened:" << std::endl;
        }
    }
    return "Not found";
};
