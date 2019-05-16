#ifndef MAKE_H
#define MAKE_H

#include "tpl.h"

class make : public tpl
{
private:
    void head() override;
    void body() override;
    void body(int sec);
    void tail() override;
    void default_color() override;
    std::vector<std::string> fake_extension_list() override;
    bool rand_shift(int const &value);

public:
    make() : tpl("make")
    {
    }
    ~make();

    void run() override;
    void run(int body_sec);
};

make::~make()
{
}

void make::head()
{
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    std::cout << "Scanning dependencies of target " << path()[rand_from_vec(path())] << std::endl;
    default_color();
    std::cout << std::endl;
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

                if (percent < 90)
                {
                    if (rand_shift(7))
                    {
                        percent++;
                    }
                }

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

                for (int z = 0; z <= depth; z++)
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

        if (percent < 10)
        {
            if (rand_shift(1023))
                percent = rand_range(0, 10);
        }
        else if ((percent > 9) && (percent < 20))
        {
            if (rand_shift(511))
                percent = rand_range(0, 20);
        }
        else if ((percent > 19) && (percent < 30))
        {
            if (rand_shift(255))
                percent = rand_range(0, 30);
        }
        else if ((percent > 29) && (percent < 40))
        {
            if (rand_shift(127))
                percent = rand_range(0, 40);
        }
        else if ((percent > 39) && (percent < 50))
        {
            if (rand_shift(63))
                percent = rand_range(20, 50);
        }
        else if ((percent > 49) && (percent < 60))
        {
            if (rand_shift(31))
                percent = rand_range(30, 60);
        }
        else if ((percent > 59) && (percent < 70))
        {
            if (rand_shift(15))
                percent = rand_range(40, 70);
        }
        else if ((percent > 69) && (percent < 80))
        {
            if (rand_shift(7))
                percent = rand_range(50, 80);
        }
        else if ((percent > 79) && (percent < 90))
        {
            if (rand_shift(3))
                percent = rand_range(60, 80);
        }
        else if ((percent > 89) && (percent < 100))
        {
            if (rand_shift(1))
                percent = rand_range(60, 80);
        }
        else
        {
            percent = rand_range(0, 99);
        }
    }
}

void make::body(int sec)
{
    int percent = 0;
    bool fl = true;

    if (sec <= 0)
        fl = false;

    auto start = sc.now();

    while (fl)
    {
        auto end = sc.now();
        auto time_span = static_cast<std::chrono::duration<double>>(end - start);
        if ((sec - time_span.count()) <= 1)
        {
            percent = 100;
        }

        std::vector<std::string> fp = fake_path();
        for (int depth = fp.size() - 1; depth >= 0; depth--)
        {
            for (int i = 0; i < rand_quantity_source_files(); i++)
            {
                rlutil::msleep(rand_time_sleep());

                if (percent < 90)
                {
                    if (rand_shift(7))
                    {
                        percent++;
                    }
                }

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

                for (int z = 0; z <= depth; z++)
                {
                    std::cout << fp[z] << "/";
                }

                std::cout << fake_source_file_name() << ".";

                std::cout << fake_extension();

                default_color();

                std::cout << std::endl;
            }
        }

        if (percent < 100)
        {
            percent++;
        }

        if (percent < 10)
        {
            if (rand_shift(1023))
                percent = rand_range(0, 10);
        }
        else if ((percent > 9) && (percent < 20))
        {
            if (rand_shift(511))
                percent = rand_range(0, 20);
        }
        else if ((percent > 19) && (percent < 30))
        {
            if (rand_shift(255))
                percent = rand_range(0, 30);
        }
        else if ((percent > 29) && (percent < 40))
        {
            if (rand_shift(127))
                percent = rand_range(0, 40);
        }
        else if ((percent > 39) && (percent < 50))
        {
            if (rand_shift(63))
                percent = rand_range(20, 50);
        }
        else if ((percent > 49) && (percent < 60))
        {
            if (rand_shift(31))
                percent = rand_range(30, 60);
        }
        else if ((percent > 59) && (percent < 70))
        {
            if (rand_shift(15))
                percent = rand_range(40, 70);
        }
        else if ((percent > 69) && (percent < 80))
        {
            if (rand_shift(7))
                percent = rand_range(50, 80);
        }
        else if ((percent > 79) && (percent < 90))
        {
            if (rand_shift(3))
                percent = rand_range(60, 80);
        }
        else if ((percent > 89) && (percent < 100))
        {
            if (rand_shift(1))
                percent = rand_range(60, 80);
        }
        else
        {
            fl = false;
        }
    }
}

void make::tail()
{
    default_color();

    std::cout << "[100%] ";
    rlutil::setColor(rlutil::LIGHTGREEN);

    std::cout << "Linking CXX executable " << path()[rand_from_vec(path())] << "\\" << source_file_name()[rand_from_vec(source_file_name())] << ".exe" << std::endl;
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
void make::run(int body_sec)
{
    head();
    if (body_sec == fakecompile::time::INFINITELY)
    {
        body();
    }
    else if (body_sec == fakecompile::time::MISSING)
    {

    }
    else if (body_sec == fakecompile::time::QUICKLY)
    {

    }
    else
    {
        body(body_sec);
    }
    tail();
}

std::vector<std::string> make::fake_extension_list()
{
    return {
        "cpp.obj"};
}

bool make::rand_shift(int const &value)
{
    std::uniform_int_distribution<> distr(0, value);
    if (value != distr(mt))
        return false;
    else
        return true;
}

#endif // MAKE_H