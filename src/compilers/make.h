#ifndef MAKE_H
#define MAKE_H

#include "tpl.h"

class make : public tpl
{
public:
    make(std::string const &name, std::vector<std::string> const &extension) : tpl(name, extension)
    {
        
    }
    ~make();
};

make::~make()
{
}


#endif // MAKE_H