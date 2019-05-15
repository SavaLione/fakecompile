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
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    std::cout << "Scanning dependencies of target " << path()[rand_from_vec(path())] << std::endl;
    default_color();
}

void make::body()
{
    int percent = 0;
    bool fl = true;
    while(fl)
    {
        std::vector<std::string> fp = fake_path();
        int depth = fp.size() - 1;

        rlutil::msleep(rand_time_sleep());

        std::cout << "[";

        if(percent < 10)
        {
            std::cout << "  " << percent << "%] ";
        }
        else if((percent > 9) && (percent < 100))
        {
            std::cout << " " << percent << "%] ";
        }
        else
        {
            std::cout << percent << "%] ";
        }

        rlutil::setColor(rlutil::GREEN);

        std::cout << "Building CXX object ";



        percent++;
        if (percent >= 100)
        {
            fl = false;
        }
    }
}

void make::tail()
{
    default_color();
    std::cout << "[100%] Built target " << path()[rand_from_vec(path())] << std::endl;
    default_color();
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