#include <iostream>

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

    return 0;
}