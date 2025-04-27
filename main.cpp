#include "HappyNumber.h"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    char *input_fn;
    char *output_fn;
    if (argc == 3) {
        input_fn = argv[1];
        output_fn = argv[2];
    }
    else {
        printf("args error");
        return -1;
    }

    try {
        std::ifstream in_stream(input_fn, std::ifstream::in);
        auto numbers = Parser::get_data(in_stream);
        in_stream.close();
        std::vector<bool> answ = {};
        for (int num: numbers) {
            HappyNumber happy(num);
            answ.emplace_back(happy.is_happy());
        }
        std::ofstream out_stream(output_fn, std::ostream::out);
        save_result(out_stream, answ, numbers);
        out_stream.close();

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return -1;
    }

    return 0;
}
