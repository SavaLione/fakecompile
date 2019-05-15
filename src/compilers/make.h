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
    make(std::string const &name, std::vector<std::string> const &extension) : tpl(name, extension)
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
    std::cout << "OK " << __PRETTY_FUNCTION__ << std::endl;
}

void make::body()
{
    std::cout << "OK " << __PRETTY_FUNCTION__ << std::endl;
}

void make::tail()
{
    std::cout << "OK " << __PRETTY_FUNCTION__ << std::endl;
}

void make::default_color()
{
    rlutil::setColor(rlutil::GREY);
}

void make::run()
{
    std::cout << "OK " << __PRETTY_FUNCTION__ << std::endl;

    head();
    body();
    tail();
}

#endif // MAKE_H