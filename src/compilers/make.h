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
    std::vector<std::string> fake_extension_list() override;

public:
    make() : tpl("make")
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
    while (fl)
    {
        std::vector<std::string> fp = fake_path();

        for (int depth = fp.size() - 1; depth >= 0; depth--)
        {
            for (int i = 0; i < rand_quantity_source_files(); i++)
            {
                rlutil::msleep(rand_time_sleep());

                std::cout << "[";

                if (percent < 10)
                {
                    std::cout << "  " << percent << "%] ";
                }
                else if ((percent > 9) && (percent < 100))
                {
                    std::cout << " " << percent << "%] ";
                }
                else
                {
                    std::cout << percent << "%] ";
                }

                rlutil::setColor(rlutil::GREEN);

                std::cout << "Building CXX object ";

                for (int z = depth; z >= 0; z--)
                {
                    std::cout << fp[z] << "/";
                }

                std::cout << fake_source_file_name() << ".";

                std::cout << fake_extension();

                default_color();

                std::cout << std::endl;
            }
        }

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

std::vector<std::string> make::fake_extension_list()
{
    return
        {
            "cpp.obj"
        };
}

#endif // MAKE_H