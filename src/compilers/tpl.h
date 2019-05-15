#ifndef TPL_H
#define TPL_H

#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <random>
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

    std::mt19937 mt;

protected:
    virtual std::vector<std::string> path();
    virtual std::vector<std::string> source_file_name();

    virtual void head();
    virtual void body();
    virtual void tail();

    virtual void default_color();

    int rand_from_vec(std::vector<std::string> const& vec);
    int rand_time_sleep();

    virtual std::vector<std::string> fake_path();
    virtual std::string fake_source_file_name();

public:
    tpl(std::string const &name, std::vector<std::string> const &extension);
    ~tpl();

    virtual void run();
};

tpl::tpl(std::string const &name, std::vector<std::string> const &extension)
{
    std::mt19937 mt(time(0));
    this->mt = mt;
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

int tpl::rand_from_vec(std::vector<std::string> const& vec)
{
    std::uniform_int_distribution<> distr(0, vec.size() - 1);
    return distr(mt);
}

int tpl::rand_time_sleep()
{
    std::uniform_int_distribution<> distr(0, 2 * 1000);
    return distr(mt);
}

std::vector<std::string> tpl::fake_path()
{
    std::vector<std::string> ret;

    std::uniform_int_distribution<> distr(1, 10);
    int depth = depth = distr(mt);

    for(int i = 0; i < depth; i++)
    {
        ret.push_back(path()[rand_from_vec(path())]);
    }

    return ret;
}

std::string tpl::fake_source_file_name()
{
    return source_file_name()[rand_from_vec(source_file_name())];
}

#endif // TPL_H