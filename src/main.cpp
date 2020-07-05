#include <iostream>

// Creational Patterns
#include "simple_factory.h"
#include "factory_method.h"

// Structural Patterns
#include "bridge.h"
#include "facade.h"

// Behavioral Patterns
#include "strategy.h"



#include "decorator.h"

using namespace std;

int main(int argc, char const *argv[]) 
{
    //SimpleFactoryTest();
    //FactoryMethodTest();
    //FacadeTest();
    //BridgeTest();

    //StrategyTest();

    decorator::DecoratorTest();
    

    system("pause");
    return 1;
}