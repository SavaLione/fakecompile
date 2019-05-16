#include "compilers/make.h"

#include <cxxopts.hpp>

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
    std::string compiler = "";
    int i_time =fakecompile::time::MISSING,
        time_sleep_MIN = fakecompile::time::MISSING, 
        time_sleep_MAX = fakecompile::time::MISSING;
	try
	{
		cxxopts::Options options("fakecompile", " - fc");

		options.add_options()
			("h,help", "Help")
			("v,version", "Version")
            ("make", "Make")
            ("c,compiler", "Compiler", cxxopts::value<std::string>(compiler))
            ("t,time", "Time to exit", cxxopts::value<int>(i_time))
            ("time_sleep_MIN", "Time sleep minimum", cxxopts::value<int>(time_sleep_MIN))
            ("time_sleep_MAX", "Time sleep maximum", cxxopts::value<int>(time_sleep_MAX));

		auto result = options.parse(argc, argv);

		if (result.count("help"))
		{
            std::cout << options.help({"", "Group"});
			exit(0);
		}
        
        if (result.count("version"))
		{
            std::cout << "fakecompile version: " << fakecompile::VERSION::VERSION << std::endl;
			exit(0);
		}

        if (result.count("make"))
		{
            make mk;

            if(time_sleep_MIN != fakecompile::time::MISSING)
                mk.set_time_sleep_MIN(time_sleep_MIN);
            
            if(time_sleep_MAX != fakecompile::time::MISSING)
                mk.set_time_sleep_MAX(time_sleep_MAX);

            if (i_time != fakecompile::time::MISSING)
            {
                mk.run(i_time);
            }
            else
            {
                mk.run();
            }

			exit(0);
		}
	}
	catch (const cxxopts::OptionException &e)
	{
        std::cerr << e.what();
		exit(1);
	}

    return 0;
}