#ifndef TPL_H
#define TPL_H

#include <vector>
#include <string>
#include <iostream>
#include <rlutil.h>

class tpl
{
private:
    void function_not_set();

protected:
    std::string name;
    std::vector<std::string> extension;

public:
    tpl(std::string const &name, std::vector<std::string> const &extension);
    ~tpl();

    virtual void head();
    virtual void body();
    virtual void tail();

    virtual void default_color();

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

void tpl::function_not_set()
{
    std::cout << __PRETTY_FUNCTION__;
}

void tpl::head()
{
    rlutil::setColor(rlutil::RED);
    function_not_set();
    std::cout << "Please set: " << "void head();" << std::endl;
    default_color();
}

void tpl::body()
{
    rlutil::setColor(rlutil::RED);
    std::cout << "Please set: " << "void body();" << std::endl;
    default_color();
}

void tpl::tail()
{
    rlutil::setColor(rlutil::RED);
    std::cout << "Please set: " << "void tail();" << std::endl;
    default_color();
}

void tpl::default_color()
{
    rlutil::setColor(rlutil::RED);
    std::cout << "Please set: " << "void defaultColor();" << std::endl;
    rlutil::setColor(rlutil::GREY);
}

void tpl::run()
{
    rlutil::setColor(rlutil::RED);
    std::cout << "Please set: " << "void run();" << std::endl;
    default_color();
}

#endif // TPL_H