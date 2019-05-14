#include "fakecompile.h"

#include <rlutil.h>

#include <iostream>
#include <string>

using namespace std;

void colorTest();

int main()
{
    cout << "fakecompile" << endl;

    colorTest();

    return 0;
}

void colorTest()
{
    for(int i = 0; i < 16; i++)
    {
        rlutil::setColor(i);
        cout << "color: [" << i << "]" << endl;
    }

    rlutil::setColor(rlutil::WHITE);
    cout << "color: [WHITE]" << endl;

    rlutil::setColor(rlutil::GREY);
    cout << "color: [GREY]" << endl;
}