#include <iostream>

#include "singleton.h"

using namespace std;

class Gaia
{
public:
    static Gaia* getInstance();
    void createEarth();
private:
    Gaia();
    static Gaia* gaia;
};

Gaia::Gaia(){}

Gaia* Gaia::getInstance()
{
    if(Gaia::gaia == NULL)
        Gaia::gaia = new Gaia();
    return Gaia::gaia;
}

void Gaia::createEarth()
{
    cout << "大地之母蓋亞孕育大地!" << endl;
}

Gaia* Gaia::gaia = NULL;

int SingletonTest()
{
    Gaia* gaia = Gaia::getInstance();
    gaia->createEarth();

    return 1;
}

