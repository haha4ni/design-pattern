#include <iostream>
#include <vector>
#include <string>

#include "observer.h"

using namespace std;

class Adventurer
{
    public:
    string name;

    Adventurer(string name)
    {
        this->name = name;
    }

    virtual void getQuestions(string questions)
    {

    }
};

class Subject
{
    public:
    vector<Adventurer*> list;

    void add(Adventurer* observer)
    {
        list.push_back(observer);
    }
    
    void remove(Adventurer* observer)
    {
        //list.push_back(observer);
    }

    virtual void sendQuestions(string questions) = 0;
};


class Association : public Subject
{
    void sendQuestions(string questions){
        for(int i=0; i<list.size(); i++)
        {
            list[i]->getQuestions(questions);
        }
    }      
};


class Knight : public Adventurer
{
    public:
    Knight(string name):Adventurer(name){}

    void getQuestions(string questions)
    {
        cout << "Knight ";
        cout << "Get Mission : " << questions << endl;
    }
};

class Bard : public Adventurer
{
    public:
    Bard(string name):Adventurer(name){}

    void getQuestions(string questions)
    {
        cout << "Bard ";
        cout << "Get Mission : " << questions << endl;
    }
};




int ObserverTest()
{
    Adventurer* knight = new Knight("Haha");
    Adventurer* bard = new Bard("Haha");

    Subject* association = new Association;
    association->add(knight);
    association->add(bard);

    association->sendQuestions("Kill Slime");

    return 1;
}