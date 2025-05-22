#include "HappyNumber.h"

#include <complex>
#include <fstream>
#include <iostream>

std::vector<int> Parser::get_data(std::istream &stream) {
    if (!stream.good()) {
        throw std::range_error( "Parser got wrong stream" );
    }
    std::string line;
    std::vector<int> input;

    while (std::getline(stream, line)) {
        if (!line.empty()) input.emplace_back(get_next(line));
    }

    return input;
}

int Parser::get_next(const std::string &line) {
    std::istringstream iss(line);
    int num;
    std::vector<int> buff {};
    while (iss >> num) {
        buff.emplace_back(num);
    }
    if (buff.size() != 1 ) throw std::runtime_error("ERROR! parser got wrong line:" + line);
    return buff[0];
}

HappyNumber::HappyNumber(int num): num(num) {
    if (num < 0) throw std::runtime_error("ERROR! wrong number");
}

bool HappyNumber::is_happy() const {
    int sum = num;
    int count = 0;
    while (sum != 1) {
        if (count > MAX_N) return false;
        int buff = 0;
        for (int i = 0; i <= std::log10(sum); i++) {
            int digit = static_cast<int>((sum / std::pow(10, i))) % 10;
            buff += digit * digit;
        }
        sum = buff;
        count++;
    }
    return sum == 1;
}

void save_result(std::ostream& stream, std::vector<bool> &answ, const std::vector<int> &input) {
    if (!stream.good()) {
        throw std::runtime_error("ERROR! bad stream");
    }
    for (int i = 0; i < input.size(); i++) {
        std::string result = answ[i] ? "true" : "false";
        stream << input[i] << " - " << result << std::endl;
    }
}


