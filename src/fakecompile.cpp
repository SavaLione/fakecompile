#include "fakecompile.h"
#include "compilers/tpl.h"

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

    tpl some(name, extension);

    some.run();

    return 0;
}