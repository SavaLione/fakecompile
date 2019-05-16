#ifndef CMAKE_H
#define CMAKE_H

#include "tpl.h"

class cmake : public tpl
{
private:
    void head() override;
    void body() override;
    void body(int sec);
    void tail() override;

public:
    cmake() : tpl("cmake")
    {
    }
    ~cmake();

    void run() override;
    void run(int body_sec);
};

cmake::~cmake()
{
}

void cmake::run()
{
    head();
    body();
    tail();
}

void cmake::run(int body_sec)
{
    head();
    if (body_sec == fakecompile::time::INFINITELY)
    {
        body();
    }
    else if (body_sec == fakecompile::time::SKIP)
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

void cmake::head()
{
    std::string s = fake_full_path();

    std::cout
        << "-- The C compiler identification is GNU 8.1.0" << std::endl
        << "-- The CXX compiler identification is GNU 8.1.0" << std::endl;
#if defined(FAKECOMPILE_WINDOWS)
    std::cout
        << "-- Check for working C compiler: C:/" << s << "/gcc.exe" << std::endl
        << "-- Check for working C compiler: C:/" << s << "/gcc.exe -- works" << std::endl;
#else
    std::cout
        << "-- Check for working C compiler: /" << s << "/cc" << std::endl
        << "-- Check for working C compiler: /" << s << "/cc -- works" << std::endl;
#endif
    std::cout
        << "-- Detecting C compiler ABI info" << std::endl
        << "-- Detecting C compiler ABI info - done" << std::endl
        << "-- Detecting C compile features" << std::endl
        << "-- Detecting C compile features - done" << std::endl;

#if defined(FAKECOMPILE_WINDOWS)
    std::cout
        << "-- Check for working CXX compiler: C:/" << s << "/g++.exe" << std::endl
        << "-- Check for working CXX compiler: C:/" << s << "/g++.exe -- works" << std::endl;
#else
    std::cout
        << "-- Check for working C compiler: /" << s << "/c++" << std::endl
        << "-- Check for working C compiler: /" << s << "/c++ -- works" << std::endl;
#endif
    std::cout
        << "-- Detecting CXX compiler ABI info" << std::endl
        << "-- Detecting CXX compiler ABI info - done" << std::endl
        << "-- Detecting CXX compile features" << std::endl
        << "-- Detecting CXX compile features - done" << std::endl;
}

void cmake::body()
{
    bool fl = true;
    while (fl)
    {
        rlutil::msleep(rand_time_sleep());
        std::string s = fake_source_file_name();
        std::cout << "-- Looking for " << s << std::endl;
        std::cout << "-- Looking for " << s << " - found" << std::endl;
        if (rand_range(0, 3) == 3)
        {
            std::cout << "-- Found " << s << ": ";
            if (rand_range(0, 1))
            {
                std::cout << "TRUE";
            }
            else
            {
                std::cout << "FALSE";
            }
            std::cout << std::endl;
        }

        if (rand_range(0,1))
        {
            rlutil::msleep(rand_time_sleep());
            std::cout << "-- " << s << " version: " << fake_version() << std::endl;
        }

        if (rand_range(0, 3) == 3)
        {
            rlutil::msleep(rand_time_sleep());
            std::vector<std::string> fp = fake_path();
            std::cout << "-- Found the following " << s << " libraries:" << std::endl;
            for (long long unsigned int depth = 0; depth < fp.size(); depth++)
            {
                std::cout << "--   " << fp[depth] << std::endl;
            }
        }
    }
}

void cmake::body(int sec)
{
    bool fl = true;

    if (sec <= 0)
        fl = false;
    
    auto start = sc.now();
    
    while (fl)
    {
        rlutil::msleep(rand_time_sleep());
        std::string s = fake_source_file_name();
        std::cout << "-- Looking for " << s << std::endl;
        std::cout << "-- Looking for " << s << " - found" << std::endl;
        if (rand_range(0, 3) == 3)
        {
            std::cout << "-- Found " << s << ": ";
            if (rand_range(0, 1))
            {
                std::cout << "TRUE";
            }
            else
            {
                std::cout << "FALSE";
            }
            std::cout << std::endl;
        }

        if (rand_range(0,1))
        {
            rlutil::msleep(rand_time_sleep());
            std::cout << "-- " << s << " version: " << fake_version() << std::endl;
        }

        if (rand_range(0, 3) == 3)
        {
            rlutil::msleep(rand_time_sleep());
            std::vector<std::string> fp = fake_path();
            std::cout << "-- Found the following " << s << " libraries:" << std::endl;
            for (long long unsigned int depth = 0; depth < fp.size(); depth++)
            {
                std::cout << "--   " << fp[depth] << std::endl;
            }
        }
        auto end = sc.now();
        auto time_span = static_cast<std::chrono::duration<double>>(end - start);
        if ((sec - time_span.count()) <= 1)
        {
            fl = false;
        }
    }
}

void cmake::tail()
{
    std::cout
        << "-- Configuring done" << std::endl
        << "-- Generating done" << std::endl
        << "-- Build files have been written to: ";
#if defined(FAKECOMPILE_WINDOWS)
    std::cout << "C:/" << fake_full_path();
#else
    std::cout << "/" << fake_full_path();
#endif
    std::cout << std::endl;
}

#endif // CMAKE_H