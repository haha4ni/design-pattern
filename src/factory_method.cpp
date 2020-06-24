#include <iostream>
#include <string>

#include "factory_method.h"

using namespace std;


class Monster
{
public:
	virtual string getType() = 0;
};

class Slime : public Monster
{
public:
	string getType()
	{
		return "Slime";
	}
};

class Orc : public Monster
{
public:
	string getType()
	{
		return "Orc";
	}
};

class FactoryCreate
{
public:
	enum monsterEnum
	{
		SLIME,
		ORC,
	};

	virtual Monster *CreateMonster()
	{
	}
};


class SlimeFactory : public FactoryCreate
{
	virtual Monster *CreateMonster()
	{
		return new Slime();
	}
};

class OrcFactory : public FactoryCreate
{
	virtual Monster *CreateMonster()
	{
		return new Orc();
	}
};
				

int FactoryMethodTest(){
	FactoryCreate* slime_factory = new SlimeFactory;
	FactoryCreate* orc_factory = new OrcFactory;

	Monster* Monster1 = slime_factory->CreateMonster();
	Monster* Monster2 = orc_factory->CreateMonster();
	
	cout << Monster1->getType() << endl;
	cout << Monster2->getType() << endl;

	return 1;
}