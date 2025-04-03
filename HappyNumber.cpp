#include "HappyNumber.h"

#include <fstream>
#include <iostream>
#include <unordered_set>

HappyNumber::HappyNumber(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("ERROR! can`t open file: " + filename);
    }

    std::string line;

    while (std::getline(file, line)) {
        int num;
        int f = sscanf_s(line.data(), "%d", &num, 10);
        if (f != 1 && line != std::string("")) {
            throw std::runtime_error("ERROR! can`t read number from file: " + filename);
        }
        input.push_back(num);
    }
}

HappyNumber::~HappyNumber() = default;

static int sum_of_squares_of_digits(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

static bool is_happy(int n) {
    std::unordered_set<int> seen;  // Множество для отслеживания повторений

    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n);  // Добавляем число в множество
        n = sum_of_squares_of_digits(n);  // Получаем сумму квадратов цифр
    }

    return n == 1;  // Если число стало 1, то оно счастливое
}

void HappyNumber::calculate() {
    for(int i = 0; i < input.size(); i++) {
        output.push_back(is_happy(input[i]));
    }
}

void HappyNumber::save_result(const std::string &filename) {
    std::fstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("ERROR! can`t open/create file: " + filename);
    }
    for (int i = 0; i < input.size(); i++) {
        std::string result = output[i] ? "true" : "false";
        file << input[i] << " - " << result << std::endl;
    }
    file.close();
}
