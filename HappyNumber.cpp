#include "HappyNumber.h"

#include <fstream>

HappyNumber::HappyNumber(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("ERROR! can`t open file: " + filename);
    }

    std::string line;

    while (std::getline(file, line)) {
        int num;
        if (sscanf_s(line.data(), "%d", &num, 10) != 1) {
            throw std::runtime_error("ERROR! can`t read number from file: " + filename);
        }
        input.push_back(num);
    }
}

HappyNumber::~HappyNumber() = default;

void HappyNumber::calculate() {

}

void HappyNumber::save_result(const std::string &filename) {
    std::fstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("ERROR! can`t open/create file: " + filename);
    }
    for (int i = 0; i < input.size(); i++) {
        file << input[i] << " - " << "true" ? output[i]: "false" << std::endl;
    }
    file.close();
}
