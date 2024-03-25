#include "Factory.h"
#include "ConcreteFactory.h"
#include "Product.h"
#include <iostream>

int main()
{
	Factory *factory = new ConcreteFactory();

	Product *pro1 = factory->createProductA();
	Product *pro2 = factory->createProductB();

	pro1->use();
	pro2->use();

	delete factory;
	delete pro1;
	delete pro2;
}