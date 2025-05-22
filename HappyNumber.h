#ifndef HAPPYNUMBER_H
#define HAPPYNUMBER_H
#include <string>
#include <vector>

#define MAX_N 1000

class Parser {
public:
    Parser() = delete;
    static std::vector<int> get_data(std::istream& stream);
private:
    static int get_next(const std::string& line);
};


class HappyNumber {
public:
    explicit HappyNumber(int num);
    ~HappyNumber() = default;

    bool is_happy() const;
private:
    const int num;
};

void save_result(std::ostream& stream, std::vector<bool> &answ, const std::vector<int> &input);


#endif //HAPPYNUMBER_H
