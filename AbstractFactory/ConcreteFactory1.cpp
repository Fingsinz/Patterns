#include "ConcreteFactory1.h"
#include "ProductA1.h"
#include "ProductB1.h"

AbstractProductA *ConcreteFactory1::createProductA()
{
	return new ProductA1();
}
AbstractProductB *ConcreteFactory1::createProductB()
{
	return new ProductB1();
}