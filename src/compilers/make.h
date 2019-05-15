#ifndef MAKE_H
#define MAKE_H

#include "tpl.h"

class make : public tpl
{
private:
    void head() override;
    void body() override;
    void tail() override;
    void default_color() override;

public:
    make() : tpl("make", {"cpp.o", "cpp.obj"})
    {

    }
    ~make();

    void run() override;
};

make::~make()
{
}

void make::head()
{
    rlutil::setColor(rlutil::MAGENTA);
    std::cout << "Scanning dependencies of target " << path()[rand_from_vec(path())] << std::endl;
    default_color();
}

void make::body()
{

}

void make::tail()
{

}

void make::default_color()
{
    rlutil::setColor(rlutil::GREY);
}

void make::run()
{
    head();
    body();
    tail();
}

#endif // MAKE_H