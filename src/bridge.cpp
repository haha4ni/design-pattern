#include <iostream>
#include "bridge.h"

using namespace std;


class Enchanting
{
    public:
    virtual void getType() = 0;
};

class Thunder : public Enchanting
{
    void getType()
    {
        cout << "Thunder";
    }
};

class Water : public Enchanting
{
    void getType()
    {
        cout << "Water";
    }
};

class Weapon
{
    Enchanting* enchanting;
    
    public:
    Weapon(Enchanting* enchanting_):enchanting(enchanting_)
    {
    }
    virtual void attack() = 0;
    virtual void getType()
    {
        enchanting->getType();
    }
};

class Sword : public Weapon
{
    public:
    Sword(Enchanting* enchanting_):Weapon(enchanting_)
    {
    }
    void attack()
    {
        this->getType();
        cout << " Slash Attack" << endl;
    }
};

class Longbow : public Weapon
{
    public:
    Longbow(Enchanting* enchanting_):Weapon(enchanting_)
    {
    }
    void attack()
    {
        this->getType();
        cout << " Shoot Attack" << endl;
    }
};

int BridgeTest()
{
    Weapon* sword = new Sword(new Thunder);
    Weapon* longbow = new Longbow(new Water);

    sword->attack();
    longbow->attack();

}