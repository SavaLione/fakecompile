#include "compilers/make.h"

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string name = "some";

    std::vector<std::string> extension;
    extension.push_back("o");
    extension.push_back("cpp");
    extension.push_back("h");

    make mk(name, extension);
    mk.run();

    return 0;
}