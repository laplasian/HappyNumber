#ifndef HAPPYNUMBER_H
#define HAPPYNUMBER_H
#include <map>
#include <string>
#include <vector>


class HappyNumber {
public:
    HappyNumber(const std::string &filename);
    ~HappyNumber();

    void calculate();
    void save_result(const std::string &filename);

    std::vector<size_t> input;
    std::vector<bool> output;
};



#endif //HAPPYNUMBER_H
