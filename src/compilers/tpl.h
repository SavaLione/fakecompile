#ifndef TPL_H
#define TPL_H

#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <chrono>
#include <random>
#include <rlutil.h>

#include "../fakecompile.h"

namespace fakecompile
{
enum time
{
    SKIP = -1,
    INFINITELY = -2,
    QUICKLY = -3,
    MISSING = -10
};
} // namespace fakecompile

class tpl
{
private:
    std::string name;

protected:
    std::mt19937 mt;
    std::chrono::steady_clock sc;

    virtual std::vector<std::string> path();
    virtual std::vector<std::string> source_file_name();
    virtual std::vector<std::string> fake_extension_list();

    virtual void head();
    virtual void body();
    virtual void tail();

    virtual void default_color();

    int rand_from_vec(std::vector<std::string> const &vec);
    int rand_time_sleep();
    int rand_quantity_source_files();
    int rand_range(int const &a, int const &b);

    virtual std::vector<std::string> fake_path();
    virtual std::string fake_source_file_name();
    virtual std::string fake_extension();
    virtual std::string fake_full_path();
    virtual std::string fake_version();

    int quantity_source_files_MAX = 10;
    int fake_path_depth_MAX = 10;
    int time_sleep_MAX = 2 * 1000;

    int quantity_source_files_MIN = 1;
    int fake_path_depth_MIN = 1;
    int time_sleep_MIN = 0;

public:
    tpl(std::string const &name);
    ~tpl();

    virtual void run();

    void set_quantity_source_files_MAX(int const& MAX);
    void set_fake_path_depth_MAX(int const& MAX);
    void set_time_sleep_MAX(int const& MAX);

    void set_quantity_source_files_MIN(int const& MIN);
    void set_fake_path_depth_MIN(int const& MIN);
    void set_time_sleep_MIN(int const& MIN);
};

tpl::tpl(std::string const &name)
{
    std::mt19937 mt(time(0));
    this->mt = mt;
    this->name = name;
}

tpl::~tpl()
{
}

void tpl::set_quantity_source_files_MAX(int const& MAX)
{
    this->quantity_source_files_MAX = MAX;
}

void tpl::set_fake_path_depth_MAX(int const& MAX)
{
    this->fake_path_depth_MAX = MAX;
}

void tpl::set_time_sleep_MAX(int const& MAX)
{
    this->time_sleep_MAX = MAX;
}

void tpl::set_quantity_source_files_MIN(int const& MIN)
{
    this->quantity_source_files_MIN = MIN;
}

void tpl::set_fake_path_depth_MIN(int const& MIN)
{
    this->fake_path_depth_MIN = MIN;
}

void tpl::set_time_sleep_MIN(int const& MIN)
{
    this->time_sleep_MIN = MIN;
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
    return {
        "kernel",
        "syscalls",
        "lib",
        "math-emu",
        "mm",
        "src",
        "oprofile",
        "arc",
        "boot",
        "dts"};
}

std::vector<std::string> tpl::source_file_name()
{
    return {
        "byteorder",
        "cachectl",
        "elf",
        "page",
        "ptrace",
        "setup",
        "sigcontext",
        "signal",
        "swab",
        "unistd"};
}

std::vector<std::string> tpl::fake_extension_list()
{
    return {
        "SET_FAKE_EXTENSION_LIST"};
}

int tpl::rand_from_vec(std::vector<std::string> const &vec)
{
    std::uniform_int_distribution<> distr(0, vec.size() - 1);
    return distr(mt);
}

int tpl::rand_time_sleep()
{
    std::uniform_int_distribution<> distr(time_sleep_MIN, time_sleep_MAX);
    return distr(mt);
}

int tpl::rand_quantity_source_files()
{
    if (quantity_source_files_MAX != 1)
    {
        std::uniform_int_distribution<> distr(quantity_source_files_MIN, quantity_source_files_MAX);
        return distr(mt);
    }
    else
    {
        return 0;
    }
}

std::vector<std::string> tpl::fake_path()
{
    std::vector<std::string> ret;

    std::uniform_int_distribution<> distr(fake_path_depth_MIN, fake_path_depth_MAX);
    int depth = distr(mt);

    for (int i = 0; i < depth; i++)
    {
        ret.push_back(path()[rand_from_vec(path())]);
    }

    return ret;
}

std::string tpl::fake_source_file_name()
{
    return source_file_name()[rand_from_vec(source_file_name())];
}

std::string tpl::fake_extension()
{
    return fake_extension_list()[rand_from_vec(fake_extension_list())];
}

std::string tpl::fake_full_path()
{
    std::string ret = "";
    std::vector<std::string> p = fake_path();
    if (p.size() > 1)
    {
        for (long long unsigned int i = 0; i < p.size() - 2; i++)
        {
            ret += p[i];
            ret += "/";
        }
        ret += p[p.size() - 1];
    }
    else
    {
        ret += p[0];
    }
    return ret;
}

std::string tpl::fake_version()
{
    std::string ret = "";

    ret += std::to_string(rand_range(0, 10));
    ret += ".";
    ret += std::to_string(rand_range(0, 20));
    ret += ".";
    ret += std::to_string(rand_range(0, 30));

    return ret;
}

int tpl::rand_range(int const &a, int const &b)
{
    std::uniform_int_distribution<> distr(a, b);
    return distr(mt);
}

#endif // TPL_H