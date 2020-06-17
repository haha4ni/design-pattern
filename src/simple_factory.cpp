#include <iostream>
#include <string>

#include "simple_factory.h"

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

class MonsterFactory
{
public:
	enum monsterEnum
	{
		SLIME,
		ORC,
	};

	Monster *CreateMonster(monsterEnum monster)
	{
		switch (monster)
		{
			case SLIME:
				return new Slime();
				break;
			case ORC:
				return new Orc();
				break;
			default:
				break;
		}
		return NULL;
	}
};

int SimpleFactoryTest(){
	MonsterFactory monsterFactory;
	
	Monster* Monster1 = monsterFactory.CreateMonster(MonsterFactory::SLIME);
	Monster* Monster2 = monsterFactory.CreateMonster(MonsterFactory::ORC);
	
	cout << Monster1->getType() << endl;
	cout << Monster2->getType() << endl;

	return 1;
}