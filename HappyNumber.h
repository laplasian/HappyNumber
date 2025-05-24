#ifndef HAPPYNUMBER_H
#define HAPPYNUMBER_H
#include <stdexcept>
#include <string>
#include <vector>

#define MAX_N 1000

class Parser {
public:
    Parser() = delete;
    static std::vector<int> get_data(std::istream& stream);
};

class HappyNumber {
public:
    explicit HappyNumber(int num): num(num) { if (num < 0) throw std::invalid_argument("ERROR! wrong number"); };
    ~HappyNumber() = default;

    bool is_happy() const;
private:
    const int num;
};

#endif //HAPPYNUMBER_H
