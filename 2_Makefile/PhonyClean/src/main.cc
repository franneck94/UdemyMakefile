#include <iostream>

#include "my_lib.h"

int main()
{
    print_hello_world();

    int i = 128000;
    short j = i;
    std::cout << j << std::endl;
}
