#include "HappyNumber.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_set>

static int sum_of_squares_of_digits(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

std::vector<int> Parser::get_data(std::istream &stream) {
    std::vector<int> numbers;
    int num;
    std::string line;
    while (std::getline(stream, line)) {
        std::istringstream iss(line);
        while (iss >> num) numbers.push_back(num);
        if ((iss.rdstate() & std::ios::failbit) && !(iss.rdstate() & std::ios::eofbit)) throw std::runtime_error("ERROR reading from file");
    }
    return numbers;
}

bool HappyNumber::is_happy() const {
    int n = num;
    std::unordered_set<int> seen;
    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n);
        n = sum_of_squares_of_digits(n);
    }
    return n == 1;
}
