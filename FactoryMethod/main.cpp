#include "Factory.h"
#include "ConcreteFactoryA.h"
#include "ConcreteFactoryB.h"
#include "Product.h"
#include <iostream>

int main()
{
	Factory *factoryA = new ConcreteFactoryA();
	Factory *factoryB = new ConcreteFactoryB();

	Product *pro1 = factoryA->createProduct();
	Product *pro2 = factoryB->createProduct();

	pro1->use();
	pro2->use();

	delete factoryA;
	delete factoryB;
	delete pro1;
	delete pro2;
}