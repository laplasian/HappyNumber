#ifndef HAPPYNUMBER_H
#define HAPPYNUMBER_H
#include <string>
#include <vector>

#define MAX_N 1000

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
