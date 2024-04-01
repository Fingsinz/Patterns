#include "ConcreteFactory2.h"
#include "ProductA2.h"
#include "ProductB2.h"

AbstractProductA *ConcreteFactory2::createProductA()
{
	return new ProductA2();
}

AbstractProductB *ConcreteFactory2::createProductB()
{
	return new ProductB2();
}