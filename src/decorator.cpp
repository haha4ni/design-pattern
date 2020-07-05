#include <iostream>
#include "decorator.h"

using namespace std;


namespace decorator{
class Weapon
{
    public:
    Weapon(){}

    virtual void getProperty() = 0;
};

class Sword : public Weapon
{
    public:
    Sword(){}

    void getProperty()
    {
        cout << "Sword" << endl;
    }
};



class ConcreteProperty : public Weapon
{
    protected:
    Weapon* weapon = NULL;

    public:
    ConcreteProperty(Weapon* weapon_)
    {
        weapon = weapon_;
    }
    void getProperty()
    {
        weapon->getProperty();
    }
};

class Dark : public ConcreteProperty
{
    public:
    Dark(Weapon* weapon_) : ConcreteProperty(weapon_){}
    void getProperty()
    {
        cout << "Dark ";
        ConcreteProperty::getProperty();
    }
};

class Light : public ConcreteProperty
{
    public:
    Light(Weapon* weapon_) : ConcreteProperty(weapon_){}
    void getProperty()
    {
        cout << "Light ";
        ConcreteProperty::getProperty();
    }
};



int DecoratorTest()
{
    Weapon* weapon = new Sword;
    weapon = new Light(weapon);
    weapon = new Dark(weapon);

    weapon->getProperty();
    return 1;
}

}

