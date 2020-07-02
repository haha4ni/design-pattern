#include <iostream>
#include "strategy.h"

using namespace std;


class ActionStrategy
{
    public:
    virtual void execute() = 0;
};

class Idle : public ActionStrategy
{
    public:
    void execute()
    {
        cout << "Idle" << endl;
    }
};

class Attack : public ActionStrategy
{
    public:
    void execute()
    {
        cout << "Attack" <<endl;
    }
};

class Defend : public ActionStrategy
{
    public:
    void execute()
    {
        cout << "Defend" <<endl;
    }
};

class Escape : public ActionStrategy
{
    public:
    void execute()
    {
        cout << "Escape" <<endl;
    }
};


class Adventurer
{
    ActionStrategy* action_strategy = NULL;

    public:
    Adventurer()
    {
        action_strategy = new Idle;
    }

    void changeAction(ActionStrategy* action_strategy_)
    {
        delete action_strategy;

        action_strategy = action_strategy_;
    }

    void execute()
    {
        action_strategy->execute();
    }
};


int StrategyTest()
{
    Adventurer adventurer;
    adventurer.execute();
    adventurer.changeAction(new Attack);
    adventurer.execute();
    adventurer.changeAction(new Defend);
    adventurer.execute();
    adventurer.changeAction(new Escape);
    adventurer.execute();
    adventurer.changeAction(new Idle);
    adventurer.execute();

    return 1;
}