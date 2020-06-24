#include <iostream>
#include "facade.h"

using namespace std;

class CastSystem
{
    public:
    int launch()
    {
        string a = "Casing!";
        cout << a <<endl;
    }
};

class EnchantSystem
{
    public:
    int launch()
    {
        cout << "Enchant!" <<endl;
    }
};

class Fireball
{
    private:
    CastSystem* cast;
    EnchantSystem* enchant;

    public:
    Fireball();
    int Attack();
};

Fireball::Fireball()
{
    cast = new CastSystem;
    enchant = new EnchantSystem;
}

int Fireball::Attack()
{
    cast->launch();
    enchant->launch();
    cout << "bow!" << endl;
}



int FacadeTest()
{
    Fireball fireball;
    fireball.Attack();

    return 1;
}