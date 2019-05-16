#include "compilers/make.h"

#include <iostream>
#include <string>
#include <vector>

int main()
{
    make mk;
    mk.set_time_sleep_MAX(100);
    mk.run();

    return 0;
}