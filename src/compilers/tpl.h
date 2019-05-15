#ifndef TPL_H
#define TPL_H

#include <vector>
#include <string>
#include <iostream>
#include <rlutil.h>

#include "../fakecompile.h"

namespace fakecompile
{
    enum time
    {
        MISSING = -1,
        INFINITELY = -2,
        QUICKLY = -3
    };
} // fakecompile

class tpl
{
private:
    std::string name;
    std::vector<std::string> extension = {"ADD_EXTENSION"};

protected:
    virtual std::vector<std::string> path();
    virtual std::vector<std::string> source_file_name();

    virtual void head();
    virtual void body();
    virtual void tail();

    virtual void default_color();

public:
    tpl(std::string const &name, std::vector<std::string> const &extension);
    ~tpl();

    virtual void run();
};

tpl::tpl(std::string const &name, std::vector<std::string> const &extension)
{
    this->name = name;
    this->extension = extension;
}

tpl::~tpl()
{
}

void tpl::head()
{
    rlutil::setColor(rlutil::RED);
    std::cout << "Please set: " << __PRETTY_FUNCTION__ << std::endl;
    default_color();
}

void tpl::body()
{
    rlutil::setColor(rlutil::RED);
    std::cout << "Please set: " << __PRETTY_FUNCTION__ << std::endl;
    default_color();
}

void tpl::tail()
{
    rlutil::setColor(rlutil::RED);
    std::cout << "Please set: " << __PRETTY_FUNCTION__ << std::endl;
    default_color();
}

void tpl::default_color()
{
    rlutil::setColor(rlutil::RED);
    std::cout << "Please set: " << __PRETTY_FUNCTION__ << std::endl;
    rlutil::setColor(rlutil::GREY);
}

void tpl::run()
{
    rlutil::setColor(rlutil::RED);
    std::cout << "Please set: " << __PRETTY_FUNCTION__ << std::endl;
    default_color();

    head();
    body();
    tail();
}

std::vector<std::string> tpl::path()
{
    return 
        {
            "kernel",
            "syscalls",
            "lib",
            "math-emu",
            "mm",
            "src",
            "oprofile",
            "arc",
            "boot",
            "dts"
        };
}

std::vector<std::string> tpl::source_file_name()
{
    return
        {
            "byteorder",
            "cachectl",
            "elf",
            "page",
            "ptrace",
            "setup",
            "sigcontext",
            "signal",
            "swab",
            "unistd"
        };
}

#endif // TPL_H