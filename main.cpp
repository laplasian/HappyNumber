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

        std::ofstream out_stream(output_fn, std::ostream::out);
        if (!out_stream.good()) throw std::runtime_error("ERROR! bad stream");
        for (auto num: numbers) {
            out_stream << num << " - " << (HappyNumber(num).is_happy() ? "true" : "false") << std::endl;
        }
        out_stream.close();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return -1;
    }

    return 0;
}
