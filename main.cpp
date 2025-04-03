#include <iostream>

#include "HappyNumber.h"

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
        HappyNumber happy_number (input_fn);

        happy_number.calculate();
        happy_number.save_result(output_fn);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return -1;
    }

    return 0;
}
