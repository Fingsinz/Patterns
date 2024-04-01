#include <iostream>
#include "AbstractFactory.h"
#include "AbstractProductA.h"
#include "AbstractProductB.h"
#include "ConcreteFactory1.h"
#include "ConcreteFactory2.h"

int main()
{
	AbstractFactory *factory1 = new ConcreteFactory1();
	AbstractProductA *productA1 = factory1->createProductA();
	AbstractProductB *productB1 = factory1->createProductB();
	productA1->use();
	productB1->eat();

	AbstractFactory *factory2 = new ConcreteFactory2();
	AbstractProductA *productA2 = factory2->createProductA();
	AbstractProductB *productB2 = factory2->createProductB();
	productA2->use();
	productB2->eat();

	delete factory1;
	delete factory2;
	delete productA1;
	delete productB1;
	delete productA2;
	delete productB2;
	return 0;
}