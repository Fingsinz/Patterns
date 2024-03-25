#include "ConcreteFactory.h"

ConcreteFactory::~ConcreteFactory()
{}

Product *ConcreteFactory::createProductA()
{
	return new ConcreteProductA();
}

Product *ConcreteFactory::createProductB()
{
	return new ConcreteProductB();
}