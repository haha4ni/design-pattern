//簡化靜態版


#include <iostream>
#include <string>

#include "Builder.h"

using namespace std;

class Weapon
{
public:
    string type;
    int atk;
    string rune;

    Weapon(){}
    void getState()
    {
        cout << "type:" << type << endl;
        cout << "atk:" << atk << endl;
        cout << "rune:" << rune << endl;
    }
};



class Builder
{
public:
    Weapon weapon_;

    Builder(string type, int atk)
    {
        weapon_.type = type;
        weapon_.atk = atk;
    };

    Builder setRune(string rune)
    {
        weapon_.rune = rune;
        return *this;
    }

    Weapon build()
    {
        return weapon_;
    }
};









int BuilderTest()
{
    Weapon weapon = Builder("Sword",999)
                    .setRune("fire rune")
                    .build();

    weapon.getState();
    
    return 1;
}